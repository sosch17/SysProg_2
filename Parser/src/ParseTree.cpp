#include "../includes/ParseTree.h";

/*
 * basis von treenode und leafnode, vor allem für linkedList von Children.
 * Type: für TypeCheck (type oder operation für leafnode)
 */
BasicNode::BasicNode() {
	this->type = noType;
	this->leaf = false;
}

Types BasicNode::getTypes() {
	return this->type;
}

void BasicNode::setTypes(Types t) {
	this->type = t;
}

bool BasicNode::isLeaf()
{
	return this->leaf;
}

void BasicNode::setLeaf(bool leaf)
{
	this->leaf = leaf;
}


/*
 * besteht aus parent und NodeTypes (welche regel benutzt wurde)
 * children: alle direkten nachfolger des Knoten
 */
TreeNode::TreeNode(TreeNode* parent, NodeTypes type) {
	this->parent = parent;
	this->nodeType = type;
	this->children = new LinkedList<BasicNode>;
	this->setLeaf(false);
}


/*
 * erster TreeNode (Wurzelknoten)
 */
TreeNode::TreeNode() {
	this->nodeType = PROG;
	this->children = new LinkedList<BasicNode>;
	this->setLeaf(false);
}

/*
 * ParseTree nimmt scanner, der gibt Ihm die Token durch getNextToken()
 * holt Token -> erschafft wurzelknoten PROG -> initiale  Methode zum Baumbau wird aufgerufen (erste Regel)
 */
ParseTree::ParseTree(Scanner* scanner) {
	this->scanner = scanner;
    this->currentToken = scanner->getNextToken();
    this->root = new TreeNode();

    cout << "Building Tree..." << endl;
    this->prog(this->root);
    cout << "Building Finished" << endl;

}

TreeNode* ParseTree::getRoot() {
	return this->root;
}

/*
 * parent TreeNode:
 * terminal: stateType des Tokens
 */
LeafNode::LeafNode(TreeNode* parent, StateTypes::State terminal, Token* token) {
	this->parent = parent;
	this->terminal = terminal;
	this->token = token;
	this->setLeaf(true);
}

/*
 * create LeafNode -> hängt leafNode an Chilrden LinkedList von parent (TreeNode) an -> next Token
 */
LeafNode* ParseTree::addLeaf(TreeNode* parent, StateTypes::State terminal, Token* token) {
//	cout << "addLeaf: " << token->getName() << endl;
	if(this->currentToken->getContent() == '\0') {
		cout << 'ENDE' << endl;
		this->currentToken = NULL;
	}
	LeafNode* leafNode = new LeafNode(parent, terminal, token);
	if(parent->getChildren()->isEmpty()) {
		parent->getChildren()->initNode(leafNode);
	} else {
		parent->getChildren()->addNode(leafNode);
	}

	this->currentToken = scanner->getNextToken();
	return leafNode;
}

StateTypes::State LeafNode::getTerminal() {
	return this->terminal;
}

NodeTypes TreeNode::getNodeType() {
	return this->nodeType;
}

TreeNode* TreeNode::getParent() {
	return this->parent;
}
TreeNode* LeafNode::getParent() {
	return this->parent;
}

Token* LeafNode::getToken() {
	return this->token;
}

/*
 * Syntax Fehler: beendet das Programm
 */
void ParseTree::error() {
	cout << "Unexpected Token: In Line - " << this->currentToken->getLine() << "  Column - " << this->currentToken->getColumn() << endl;
	exit (EXIT_FAILURE); //exitcode 0 oder 1

}

LinkedList<BasicNode>* TreeNode::getChildren() {
	return this->children;
}

/*
 * prüft ob aktuelles Token den übergebenen  State hat -> sonst error
 */
void ParseTree::checkTokenType(StateTypes::State stateType)
{
	if(this->currentToken->getName() != stateType)
	{
		this->error();
	}
}

/*
 * fügt TreeNode hinzu: s. AddLeaf aber mit Treenode
 */
TreeNode* ParseTree::addNode(TreeNode* parent, NodeTypes type) {
	TreeNode* treeNode = new TreeNode(parent, type);
//	cout << "addNode: " << type << ", " << endl;
	if(parent->getChildren()->isEmpty()) {
		parent->getChildren()->initNode(treeNode);
	} else {
		parent->getChildren()->addNode(treeNode);
	}
	return treeNode;
}

/*
 * vgl. Tabelle
 * prüft ob terminal (token) von dem Regel Type erreicht werden kann
 */
bool ParseTree::isReachableTerminal(Token* token, NodeTypes type) {

	StateTypes::State tokenType = token->getName();

	//DECL := int ARRAY identifier
	if(type == DECL) {
		return tokenType == StateTypes::intState3;

	//DECLS := DECL ; DECLs | E
	} else if(type == DECLS) {
		return tokenType == StateTypes::intState3    //intState? write read states gibt es nicht... sind die im umgebauten automat??
				|| tokenType == StateTypes::identifierState
				|| tokenType == StateTypes::geschwKlammerAufState
				|| tokenType == StateTypes::IFgrossState2
				|| tokenType == StateTypes::IFkleinState2
				|| tokenType == StateTypes::WHILEgrossState5
				|| tokenType == StateTypes::WHILEkleinState5
				|| tokenType == StateTypes::writeState5
				|| tokenType == StateTypes::readState4;

	//STATEMENTS := STATEMENT ; STATEMENTs | E
	} else if(type == STATEMENTS) {
		return tokenType == StateTypes::identifierState
				|| tokenType == StateTypes::writeState5
				|| tokenType == StateTypes::readState4
				|| tokenType == StateTypes::IFgrossState2
				|| tokenType == StateTypes::IFkleinState2
				|| tokenType == StateTypes::WHILEgrossState5
				|| tokenType == StateTypes::WHILEkleinState5
				|| tokenType == StateTypes::geschwKlammerAufState
				|| tokenType == StateTypes::geschwKlammerZuState;

	/*STATEMENT := identifier INDEX := EXP
				|write ( EXP )
				|read ( identifier INDEX )
				|{ STATEMENTs }
				|if ( EXP ) STATEMENT else STATEMENT
				|while ( EXP ) STATEMENT

	*/
	} else if(type == STATEMENT) {
		return tokenType == StateTypes::identifierState
				||tokenType ==StateTypes::writeState5
				||tokenType == StateTypes::readState4
				|| tokenType == StateTypes::IFgrossState2
				||tokenType == StateTypes::IFkleinState2
				|| tokenType == StateTypes::WHILEgrossState5
				||tokenType == StateTypes::WHILEkleinState5
				||tokenType == StateTypes::geschwKlammerAufState;

	// ARRAY := [ integer ] | E
	} else if(type == ARRAY) {
		return tokenType == StateTypes::identifierState
				|| tokenType == StateTypes::eckigeKlammerAufState;

	//EXP := EXP2 OP_EXP
	} else if(type == EXP) {
		return tokenType == StateTypes::identifierState
				|| tokenType == StateTypes::integerState
				|| tokenType == StateTypes::klammerAufState
				|| tokenType == StateTypes::minusState
				|| tokenType == StateTypes::ausrufezeichenState;

	/*EXP2 := ( EXP )
	 * 		|identifier INDEX
	 * 		|integer
	 * 		|- EXP2
	 * 		|! EXP2
	 */
	} else if(type == EXP2) {
		return tokenType == StateTypes::identifierState
				||tokenType == StateTypes::integerState
				||tokenType == StateTypes::klammerAufState
				|| tokenType == StateTypes::minusState
				|| tokenType == StateTypes::ausrufezeichenState;

	//OP_EXP := OP EXP | E
	} else if(type == OPEXP) {
		return tokenType == StateTypes::elseGrossState4
				||tokenType == StateTypes::elseKleinState4
				||tokenType == StateTypes::semikolonState
				||tokenType == StateTypes::eckigeKlammerZuState
				||tokenType == StateTypes::klammerZuState
				||tokenType == StateTypes::geschwKlammerZuState
				||tokenType == StateTypes::plusState
				||tokenType == StateTypes::minusState
				||tokenType == StateTypes::sternState
				||tokenType == StateTypes::doppelpunktState
				||tokenType == StateTypes::groesserState
				||tokenType == StateTypes::kleinerState
				||tokenType == StateTypes::gleichState
				||tokenType == StateTypes::gleichDoppelpunktGleichState
				||tokenType == StateTypes::undUndState;


	//OP := + | - | * | : | < | > | = | =:= | &&
	} else if(type == OP) {
		return tokenType == StateTypes::plusState
				||tokenType == StateTypes::minusState
				||tokenType == StateTypes::sternState
				||tokenType == StateTypes::doppelpunktState
				||tokenType == StateTypes::groesserState
				||tokenType == StateTypes::kleinerState
				||tokenType == StateTypes::gleichState
				||tokenType == StateTypes::gleichDoppelpunktGleichState
				||tokenType == StateTypes::undUndState;

	//INDEX := [ EXP ] | E
	} else if(type == INDEX) {
		return tokenType == StateTypes::eckigeKlammerAufState
				||tokenType == StateTypes::eckigeKlammerZuState
				||tokenType == StateTypes::klammerZuState
				||tokenType == StateTypes::geschwKlammerZuState
				||tokenType == StateTypes::doppepunktGleichState;

	}
	return false;
}

/*
 * PROG := DECLS STATEMENTS
 * wenn token nicht reachable füge EPSILON TreeNode hinzu
 */
void ParseTree::prog(TreeNode* parent){
	if(this->isReachableTerminal(this->currentToken, DECLS)) {
		this->decls(parent);
	} else {
		TreeNode* node = this->addNode(parent, DECLS);
		this->addNode(node, EPSILON);
	}

	if(this->isReachableTerminal(this->currentToken, STATEMENTS)) {
			this->statements(parent);
	} else {
		TreeNode* node = this->addNode(parent, STATEMENTS);
		this->addNode(node, EPSILON);
	}
	// not needed
	if(this->isReachableTerminal(this->currentToken, DECLS) && this->isReachableTerminal(this->currentToken, STATEMENTS))
	{
		this->error();
	}
}

/* DECLS := DECL; DECLS | ep
 * while: regel wiederholt sich für mehrere DECLS
 */
void ParseTree::decls(TreeNode* parent){

	if(this->isReachableTerminal(this->currentToken, DECL)) {
		TreeNode* node = this->addNode(parent, DECLS);
		this->decl(node);
		this->checkTokenType(StateTypes::semikolonState);
		this->addLeaf(node, StateTypes::semikolonState, this->currentToken);
			// GIBTS JA SCHON IN DECLS WEIL WIR IN DER METHODE SIND
			this->decls(node);
			// DECL oder DECLS
			while(this->isReachableTerminal(this->currentToken, DECL)) {
				this->decl(node);
				  this->addLeaf(node, StateTypes::semikolonState, this->currentToken);
			}
	} else {
		TreeNode* node = this->addNode(parent, DECLS);
		this->addNode(node, EPSILON);
	}
	//kein error() da decls epsilon sein kann

}

/* DECL := int ARRAY identifier
 * checkt ob token intState ist -> addLead -> check ob reachable mit ARRAY -> addNode -> check ob token
 * identifier ist -> addLeaf
 */
void ParseTree::decl(TreeNode* parent){
	TreeNode* node = this->addNode(parent, DECL);

	this->checkTokenType(StateTypes::intState3);
	this->addLeaf(node, StateTypes::intState3, this->currentToken);

	if(this->isReachableTerminal(this->currentToken, ARRAY)) {
		this->array(node);
	}
	else{
		this->error();
	}
	this->checkTokenType(StateTypes::identifierState);
	  this->addLeaf(node, StateTypes::identifierState, this->currentToken);

}

/*
 * ARRAY := [integer] | ep
 */
void ParseTree::array(TreeNode* parent){

	if(this->currentToken->getName() == StateTypes::eckigeKlammerAufState)
	{
		TreeNode* node = this->addNode(parent, ARRAY);
		this->addLeaf(node, StateTypes::eckigeKlammerAufState, this->currentToken);
		this->checkTokenType(StateTypes::integerState);
		this->addLeaf(node, StateTypes::integerState, this->currentToken);
		this->checkTokenType(StateTypes::eckigeKlammerZuState);
		this->addLeaf(node, StateTypes::eckigeKlammerZuState, this->currentToken);
	} else {
		TreeNode* node = this->addNode(parent, ARRAY);
	    this->addNode(node, EPSILON);
	}
	//kein error() da array epsilon sein kann

}

/* STATEMENTS := STATEMENT; STATEMENTS | ep
 */
void ParseTree::statements(TreeNode* parent){

	if(this->isReachableTerminal(this->currentToken, STATEMENT)) {
		TreeNode* node = this->addNode(parent, STATEMENTS);
		this->statement(node);
		this->checkTokenType(StateTypes::semikolonState);
		this->addLeaf(node, StateTypes::semikolonState, this->currentToken);

			this->statements(node);
			// STATEMENT oder STATEMENTS
			while(this->isReachableTerminal(this->currentToken, STATEMENT)) {
				this->statement(node);
				this->checkTokenType(StateTypes::semikolonState);
				this->addLeaf(node, StateTypes::semikolonState, this->currentToken);
			}
	} else {
		TreeNode* node = this->addNode(parent, STATEMENTS);
		this->addNode(node, EPSILON);
	}
	//kein error() da array epsilon sein kann

}

/*
 * STATEMENT := identifier INDEX := EXP | write( EXP ) | read ( identifier INDEX) | {STATEMENTS} |
 * if ( EXP ) STATEMENT else STATEMENT | while ( EXP ) STATEMENT
 */
void ParseTree::statement(TreeNode* parent){

	if(this->currentToken->getName() == StateTypes::identifierState) {
		TreeNode* node = this->addNode(parent, STATEMENT);

		this->addLeaf(node, StateTypes::identifierState, this->currentToken);

		if(this->isReachableTerminal(this->currentToken, INDEX)) {
			this->index(node);
		}
		else{
			this->error();
		}
		//HIER
		this->checkTokenType(StateTypes::doppepunktGleichState);
		this->addLeaf(node, StateTypes::doppepunktGleichState, this->currentToken);

		if(this->isReachableTerminal(this->currentToken, EXP)) {
			this->exp(node);
		}
		else{
			this->error();
		}

	} else if(this->currentToken->getName() == StateTypes::writeState5) {
		TreeNode* node = this->addNode(parent, STATEMENT2);

		this->addLeaf(node, StateTypes::writeState5, this->currentToken);
		this->checkTokenType(StateTypes::klammerAufState);
		this->addLeaf(node, StateTypes::klammerAufState, this->currentToken);

		if(this->isReachableTerminal(this->currentToken, EXP)) {
			this->exp(node);
		}
		else{
			this->error();
		}

		this->checkTokenType(StateTypes::klammerZuState);
		this->addLeaf(node, StateTypes::klammerZuState, this->currentToken);

	} else if(this->currentToken->getName() == StateTypes::readState4) {
		TreeNode* node = this->addNode(parent, STATEMENT3);

		this->addLeaf(node, StateTypes::readState4, this->currentToken);
		this->checkTokenType(StateTypes::klammerAufState);
		this->addLeaf(node, StateTypes::klammerAufState, this->currentToken);

		this->checkTokenType(StateTypes::identifierState);
		this->addLeaf(node, StateTypes::identifierState, this->currentToken);
		if(this->isReachableTerminal(this->currentToken, INDEX)) {
			this->index(node);
		}
		else{
			this->error();
		}

		  this->checkTokenType(StateTypes::klammerZuState);
		  this->addLeaf(node, StateTypes::klammerZuState, this->currentToken);

	} else if(this->currentToken->getName() == StateTypes::geschwKlammerAufState) {
		TreeNode* node = this->addNode(parent, STATEMENT4);

		this->addLeaf(node, StateTypes::geschwKlammerAufState ,this->currentToken);

		if(this->isReachableTerminal(this->currentToken, STATEMENTS)) {
			this->statements(node);
		}
		else{
			this->error();
		}

		this->checkTokenType(StateTypes::geschwKlammerZuState);
		this->addLeaf(node, StateTypes::geschwKlammerZuState, this->currentToken);
	} else if(this->currentToken->getName() == StateTypes::IFkleinState2) {
		TreeNode* node = this->addNode(parent, STATEMENT5);

		this->addLeaf(node, StateTypes::IFkleinState2 ,this->currentToken);
		this->checkTokenType(StateTypes::klammerAufState);
		this->addLeaf(node, StateTypes::klammerAufState, this->currentToken);

		if(this->isReachableTerminal(this->currentToken, EXP)) {
			this->exp(node);
		}
		else{
			this->error();
		}

		this->checkTokenType(StateTypes::klammerZuState);
		this->addLeaf(node, StateTypes::klammerZuState, this->currentToken);

		if(this->isReachableTerminal(this->currentToken, STATEMENT)) {
			this->statement(node);
		}
		else{
			this->error();
		}
		// current token ist bei elseKleinState1
		this->checkTokenType(StateTypes::elseKleinState4);
		this->addLeaf(node, StateTypes::elseKleinState4 ,this->currentToken);

		if(this->isReachableTerminal(this->currentToken, STATEMENT)) {
			this->statement(node);
		}
		else{
			this->error();
		}
	} else if(this->currentToken->getName() == StateTypes::WHILEkleinState5) {
		TreeNode* node = this->addNode(parent, STATEMENT6);

		this->addLeaf(node, StateTypes::WHILEkleinState5 ,this->currentToken);
		this->checkTokenType(StateTypes::klammerAufState);
		this->addLeaf(node, StateTypes::klammerAufState, this->currentToken);

		if(this->isReachableTerminal(this->currentToken, EXP)) {
			this->exp(node);
		}
		else{
			this->error();
		}

		this->checkTokenType(StateTypes::klammerZuState);
		this->addLeaf(node, StateTypes::klammerZuState, this->currentToken);

		if(this->isReachableTerminal(this->currentToken, STATEMENT)) {
			this->statement(node);
		}
		else{
			this->error();
		}
	}
	else{
		this->error();
	}

}

/*
 * EXP := EXP2 OP_EXP
 */
void ParseTree::exp(TreeNode* parent){
	TreeNode* node = this->addNode(parent, EXP);
	// theoretisch muss in EXP2 was drin sein
//		if(this->isReachableTerminal(this->currentToken, EXP2) || this->isReachableTerminal(this->currentToken, OPEXP)) {
//			this->exp2(node);
//			this->op_exp(node);
//		}
//		else{
//			this->error();
//		}

		if(this->isReachableTerminal(this->currentToken, EXP2)) {
			this->exp2(node);
		} else {
			this->error();
		}

		if(this->isReachableTerminal(this->currentToken, OPEXP)) {
			this->op_exp(node);
		} else {
			TreeNode* node = this->addNode(parent, OPEXP);
			this->addNode(node, EPSILON);
		}
}

/*
 * EXP2 := ( EXP ) | identifier INDEX | integer | - EXP2 | ! EXP2
 */
void ParseTree::exp2(TreeNode* parent){

	if(this->currentToken->getName() == StateTypes::klammerAufState){
		TreeNode* node = this->addNode(parent, EXP2);

		this->addLeaf(node, StateTypes::klammerAufState, this->currentToken);

		if(isReachableTerminal(this->currentToken, EXP)){
			this->exp(node);
		}
		else{
			this->error();
		}

		this->checkTokenType(StateTypes::klammerZuState);
		this->addLeaf(node, StateTypes::klammerZuState, this->currentToken);
	}
	else if(this->currentToken->getName() == StateTypes::identifierState){
		TreeNode* node = this->addNode(parent, EXP2_2);

		  this->addLeaf(node, StateTypes::identifierState, this->currentToken);
// macht ja dann gar kein epsilon weil es nicht reachable ist-> anfügen??
		if(isReachableTerminal(this->currentToken, INDEX)){
			this->index(node);
		}
//		kein error da index epsilaon sein kann
//		else{
//			this->error();
//		}

	}
	else if(this->currentToken->getName() == StateTypes::integerState){
		TreeNode* node = this->addNode(parent, EXP2_3);

		  this->addLeaf(node, StateTypes::integerState, this->currentToken);
	}
	else if(this->currentToken->getName() == StateTypes::minusState){
		TreeNode* node = this->addNode(parent, EXP2_4);

		  this->addLeaf(node, StateTypes::minusState, this->currentToken);

		if(isReachableTerminal(this->currentToken, EXP2)){
			this->exp2(node);
		}
		else{
			this->error();
		}
	}
	else if(this->currentToken->getName() == StateTypes::ausrufezeichenState){
		TreeNode* node = this->addNode(parent, EXP2_5);

		  this->addLeaf(node, StateTypes::ausrufezeichenState, this->currentToken);

		if(isReachableTerminal(this->currentToken, EXP2)){
			this->exp2(node);
		}
		else{
			this->error();
		}
	}
	else{
		this->error();
	}
}
/*
 * INDEX := [ EXP ] | ep
 */
void ParseTree::index(TreeNode* parent){

	if(this->currentToken->getName() == StateTypes::eckigeKlammerAufState){
		TreeNode* node = this->addNode(parent, INDEX);
		  this->addLeaf(node, StateTypes::eckigeKlammerAufState, this->currentToken);

			if(isReachableTerminal(this->currentToken, EXP)){
				this->exp(node);
			}
			else{
				this->error();
			}

			this->checkTokenType(StateTypes::eckigeKlammerZuState);
			this->addLeaf(node, StateTypes::eckigeKlammerZuState, this->currentToken);
	} else {
		TreeNode* node = this->addNode(parent, INDEX);
		this->addNode(node, EPSILON);
	}
	//kein error() da index epsilon sein kann

}
/*
 * OP_EXP := OP EXP | ep
 */
void ParseTree::op_exp(TreeNode* parent){

		//if(isReachableTerminal(t, OP) || isReachableTerminal(t, EXP)){
	if(isReachableTerminal(this->currentToken, OP) ){
		TreeNode* node = this->addNode(parent, OPEXP);
			this->op(node);
			this->exp(node);
	} else {
		TreeNode* node = this->addNode(parent, OPEXP);
		this->addNode(node, EPSILON);
	}
	//kein error() da index epsilon sein kann

}
/*
 * OP := + | - | * | : | < | > | = | =:= | &&
 */
void ParseTree::op(TreeNode* parent){

	if(this->currentToken->getName() == StateTypes::plusState){
		TreeNode* node = this->addNode(parent, OP);
		  this->addLeaf(node, StateTypes::plusState, this->currentToken);
	}
	else if(this->currentToken->getName() == StateTypes::minusState)
	{
		TreeNode* node = this->addNode(parent, OP2);
		  this->addLeaf(node, StateTypes::minusState, this->currentToken);
	}
	else if(this->currentToken->getName() == StateTypes::sternState)
	{
		TreeNode* node = this->addNode(parent, OP3);
		  this->addLeaf(node, StateTypes::sternState, this->currentToken);
	}
	else if(this->currentToken->getName() == StateTypes::doppelpunktState)
	{
		TreeNode* node = this->addNode(parent, OP4);
		  this->addLeaf(node, StateTypes::doppelpunktState, this->currentToken);
	}
	else if(this->currentToken->getName() == StateTypes::kleinerState)
	{
		TreeNode* node = this->addNode(parent, OP5);
		  this->addLeaf(node, StateTypes::kleinerState, this->currentToken);
	}
	else if(this->currentToken->getName() == StateTypes::groesserState)
	{
		TreeNode* node = this->addNode(parent, OP6);
		  this->addLeaf(node, StateTypes::groesserState, this->currentToken);
	}
	else if(this->currentToken->getName() == StateTypes::gleichState)
	{
		TreeNode* node = this->addNode(parent, OP7);
		  this->addLeaf(node, StateTypes::gleichState, this->currentToken);
	}
	else if(this->currentToken->getName() == StateTypes::gleichDoppelpunktGleichState)
	{
		TreeNode* node = this->addNode(parent, OP8);
		  this->addLeaf(node, StateTypes::gleichDoppelpunktGleichState, this->currentToken);
	}
	else if(this->currentToken->getName() == StateTypes::undUndState)
	{
		TreeNode* node = this->addNode(parent, OP9);
		  this->addLeaf(node, StateTypes::undUndState, this->currentToken);
	}
	else{
		this->error();
	}

}



