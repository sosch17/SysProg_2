/*
 *
 *
 */
#include "../includes/TypeCheck.h"

TypeCheck::TypeCheck(ParseTree* tree) {
	this->tree = tree;
	this->root = tree->getRoot();
	this->progTC(this->root);
}

Types TypeCheck::progTC(TreeNode* node) {
	TreeNode* c1 = (TreeNode*) node->getChildren()->getHead()->getData();
	TreeNode* c2 =
			(TreeNode*) node->getChildren()->getHead()->getNext()->getData();
	if (c1->getNodeType() != EPSILON) {
		this->declsTC(c1);
	}

	this->statementsTC(c2);

	node->setTypes(noType); // eigentlich egal da default noType

}

Types TypeCheck::declsTC(TreeNode* node) {
	TreeNode* c1 = (TreeNode*) node->getChildren()->getHead()->getData();
	TreeNode* c3 =
			(TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getData();

	if(c1->getNodeType() == EPSILON) {
		node->setTypes(noType);
				return noType;
	} else {
		this->declTC(c1);
		this->declsTC(c3);
		node->setTypes(noType);
				return noType;
	}

}

Types TypeCheck::declTC(TreeNode* node) {
	TreeNode* c2 =
			(TreeNode*) node->getChildren()->getHead()->getNext()->getData();
	LeafNode* c3 =
			(LeafNode*) node->getChildren()->getHead()->getNext()->getNext()->getData();
	this->arrayTC(c2);
	Types arrayResultType = c2->getTypes();
	if (c3->getToken()->getKey()->getType() == "intArrayType"
			|| c3->getToken()->getKey()->getType() == "intType") {
		cout << "identifier already defined. Error in Line - "
				<< c3->getToken()->getLine() << "  Column - "
				<< c3->getToken()->getColumn() << endl;
		node->setTypes(errorType);
		return errorType;
	} else if (arrayResultType == arrayType) {
		c3->getToken()->getKey()->setType("intArrayType");
		node->setTypes(intArrayType);
		return intArrayType;
		//wenn arrayTC einen arrayType ergeben hat, dann wird c3 zu intArrayType, ansonsten intType
	} else if (arrayResultType == noType) {
		c3->getToken()->getKey()->setType("intType");
		node->setTypes(intType);
		return intType;
	}
}

Types TypeCheck::arrayTC(TreeNode* node) {
	// was wenns leafnode ist??
	TreeNode* c1 = (TreeNode*) node->getChildren()->getHead()->getData();

	if (c1->getNodeType() == EPSILON) {   //Epsilon
		node->setTypes(noType);
		return noType;
	} else {
		LeafNode* c1 = (LeafNode*) node->getChildren()->getHead()->getData();
		LeafNode* c2 = (LeafNode*) node->getChildren()->getHead()->getNext()->getData();
		if (c2->getToken()->getContentInt() > 0) {
			node->setTypes(arrayType);
			return arrayType;
		} else {
			cout << "No valid dimensions." << c2->getToken()->getLine()
					<< "  Column - " << c2->getToken()->getColumn() << endl;
			node->setTypes(errorType);
			return errorType;
		}
	}
}

Types TypeCheck::statementsTC(TreeNode* node) {

	TreeNode* c1 = (TreeNode*) node->getChildren()->getHead()->getData();

	if(c1->getNodeType() == EPSILON) {
		node->setTypes(noType);
		return noType;
	} else {
		TreeNode* c3 = (TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getData();

		switch (c1->getNodeType()) {
		case STATEMENT:
			this->statementTC(c1);
			break;
		case STATEMENT2:
			this->statementTC2(c1);
			break;
		case STATEMENT3:
			this->statementTC3(c1);
			break;
		case STATEMENT4:
			this->statementTC4(c1);
			break;
		case STATEMENT5:
			this->statementTC5(c1);
			break;
		case STATEMENT6:
			this->statementTC6(c1);
			break;
		}

		this->statementsTC(c3);
		node->setTypes(noType);
		return noType;
	}

}

Types TypeCheck::statementTC(TreeNode* node) {
	LeafNode* c1 = (LeafNode*) node->getChildren()->getHead()->getData();
	TreeNode* c2 =
			(TreeNode*) node->getChildren()->getHead()->getNext()->getData();
	TreeNode* c4 =
			(TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getNext()->getData();

	this->indexTC(c2);
	Types indexResultType = c2->getTypes();
	this->expTC(c4);
	Types expResultType = c4->getTypes();

	if (c1->getToken()->getKey()->getType() == "intArrayType"
			|| c1->getToken()->getKey()->getType() == "intType") {
		cout << "Identifier not defined." << c1->getToken()->getLine()
				<< "  Column - " << c1->getToken()->getColumn() << endl;
		node->setTypes(errorType);
		return errorType;
	} else if (expResultType == intType
			&& ((c1->getToken()->getKey()->getType() == "intType"
					&& indexResultType == noType)
					|| (c1->getToken()->getKey()->getType() == "intArrayType"
							&& indexResultType == arrayType))) {
		node->setTypes(noType);
		return noType;
	} else {
		cout << "Incompatible types." << c1->getToken()->getLine()
				<< "  Column - " << c1->getToken()->getColumn() << endl;
		node->setTypes(errorType);
		return errorType;
	}

}

Types TypeCheck::statementTC2(TreeNode* node) {
	TreeNode* c3 = (TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getData();

	return this->expTC(c3);  //return?
}

Types TypeCheck::statementTC3(TreeNode* node) {

	LeafNode* c3 =
			(LeafNode*) node->getChildren()->getHead()->getNext()->getNext()->getData();
	TreeNode* c4 =
			(TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getNext()->getData();

	this->indexTC(c4);
	Types indexResultType = c4->getTypes();

	if (c3->getToken()->getKey()->getType() == "intArrayType"
			|| c3->getToken()->getKey()->getType() == "intType") {
		cout << "Identifier not defined." << c3->getToken()->getLine()
				<< "  Column - " << c3->getToken()->getColumn() << endl;
		node->setTypes(errorType);
		return errorType;
	} else if ((c3->getToken()->getKey()->getType() == "intType"
			&& indexResultType == noType)
			|| (c3->getToken()->getKey()->getType() == "intArrayType"
					&& indexResultType == arrayType)) {
		node->setTypes(noType);
		return noType;  //return?
	} else {
		cout << "Incompatible types." << c3->getToken()->getLine()
				<< "  Column - " << c3->getToken()->getColumn() << endl;
		node->setTypes(errorType);
		return errorType;
	}
}

Types TypeCheck::statementTC4(TreeNode* node) {
	TreeNode* c2 =
			(TreeNode*) node->getChildren()->getHead()->getNext()->getData();

	this->statementsTC(c2);
	node->setTypes(noType);
	return noType; //return??
}

Types TypeCheck::statementTC5(TreeNode* node) {
	TreeNode* c3 =
			(TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getData();
	TreeNode* c5 =
			(TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getNext()->getNext()->getData();
	TreeNode* c7 =
			(TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->getData();

	this->expTC(c3);
	Types expResultType = c3->getTypes();

	switch (c5->getNodeType()) {
	case STATEMENT:
		this->statementTC(c5);
		break;
	case STATEMENT2:
		this->statementTC2(c5);
		break;
	case STATEMENT3:
		this->statementTC3(c5);
		break;
	case STATEMENT4:
		this->statementTC4(c5);
		break;
	case STATEMENT5:
		this->statementTC5(c5);
		break;
	case STATEMENT6:
		this->statementTC6(c5);
		break;
	}

	switch (c7->getNodeType()) {
	case STATEMENT:
		this->statementTC(c7);
		break;
	case STATEMENT2:
		this->statementTC2(c7);
		break;
	case STATEMENT3:
		this->statementTC3(c7);
		break;
	case STATEMENT4:
		this->statementTC4(c7);
		break;
	case STATEMENT5:
		this->statementTC5(c7);
		break;
	case STATEMENT6:
		this->statementTC6(c7);
		break;
	}

	if (expResultType == errorType) {
		node->setTypes(errorType);
		return errorType;
	} else {
		node->setTypes(noType);
		return noType;
	}
}

Types TypeCheck::statementTC6(TreeNode* node) {
	TreeNode* c3 =
			(TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getData();
	TreeNode* c5 =
			(TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getNext()->getNext()->getData();

	this->expTC(c3);
	Types expResultType = c3->getTypes();

	switch (c5->getNodeType()) {
	case STATEMENT:
		this->statementTC(c5);
		break;
	case STATEMENT2:
		this->statementTC2(c5);
		break;
	case STATEMENT3:
		this->statementTC3(c5);
		break;
	case STATEMENT4:
		this->statementTC4(c5);
		break;
	case STATEMENT5:
		this->statementTC5(c5);
		break;
	case STATEMENT6:
		this->statementTC6(c5);
		break;
	}

	if (expResultType == errorType) {
		node->setTypes(errorType);
		return errorType;
	} else {
		node->setTypes(noType);
		return noType;
	}
}


Types TypeCheck::indexTC(TreeNode* node) {
// was wenn nicht epsilon und das ist eigentlich ein leafnode??
	TreeNode* c1 = (TreeNode*) node->getChildren()->getHead()->getData();

	if (c1->getNodeType() == EPSILON) {  // EPSILON
		node->setTypes(noType);
		return noType;

	} else {
		TreeNode* c2 = (TreeNode*) node->getChildren()->getHead()->getNext()->getData();

		this->expTC(c2);
		Types expResultType = c2->getTypes();

		if(expResultType == errorType)
		{
			node->setTypes(errorType);
			return errorType;
		}
		else{
			node->setTypes(arrayType);
			return arrayType;
		}
	}


}


Types TypeCheck::expTC(TreeNode* node) {
	TreeNode* c1 = (TreeNode*) node->getChildren()->getHead()->getData();
	TreeNode* c2 = (TreeNode*) node->getChildren()->getHead()->getNext()->getData();

	switch (c1->getNodeType()) {
		case EXP2:
			this->exp2TC(c1);
			break;
		case EXP2_2:
			this->exp2TC2(c1);
			break;
		case EXP2_3:
			this->exp2TC3(c1);
			break;
		case EXP2_4:
			this->exp2TC4(c1);
			break;
		case EXP2_5:
			this->exp2TC5(c1);
			break;
		}


	Types exp2ResultType = c1->getTypes();

	this->op_expTC(c2);
	Types opExpResultType = c2->getTypes();

	if(exp2ResultType == noType)
	{
		node->setTypes(exp2ResultType);
		return exp2ResultType;
	}
	else if(opExpResultType != exp2ResultType)
	{
		node->setTypes(errorType);
		return errorType;
	}
	else{
		node->setTypes(exp2ResultType);
		return exp2ResultType;
	}


}


Types TypeCheck::exp2TC(TreeNode* node) {
	TreeNode* c2 = (TreeNode*) node->getChildren()->getHead()->getNext()->getData();

	this->expTC(c2);
	Types expResultType = c2->getTypes();
	return expResultType;
}

Types TypeCheck::exp2TC2(TreeNode* node) {
	LeafNode* c1 = (LeafNode*) node->getChildren()->getHead()->getData();
	TreeNode* c2 = (TreeNode*) node->getChildren()->getHead()->getNext()->getData();

	this->indexTC(c2);
	Types indexResultType = c2->getTypes();

	if (c1->getToken()->getKey()->getType() == "intArrayType"
			|| c1->getToken()->getKey()->getType() == "intType") {
		cout << "Identifier not defined." << c1->getToken()->getLine()
				<< "  Column - " << c1->getToken()->getColumn() << endl;
		node->setTypes(errorType);
		return errorType;
	} else if(c1->getToken()->getKey()->getType() == "intType" && indexResultType == noType) {
		node->setTypes(intType);
		return intType;
	} else if(c1->getToken()->getKey()->getType() == "intArrayType" && indexResultType == arrayType) {
		node->setTypes(intType);
	} else {
		cout << "No primitive type" << c1->getToken()->getLine()
						<< "  Column - " << c1->getToken()->getColumn() << endl;
				node->setTypes(errorType);
				return errorType;
	}
}

Types TypeCheck::exp2TC3(TreeNode* node) {
	LeafNode* c1 = (LeafNode*) node->getChildren()->getHead()->getData();

	node->setTypes(intType);
	return intType;
}

Types TypeCheck::exp2TC4(TreeNode* node) {
	TreeNode* c2 = (TreeNode*) node->getChildren()->getHead()->getNext()->getData();

	switch (c2->getNodeType()) {
		case EXP2:
			this->exp2TC(c2);
			break;
		case EXP2_2:
			this->exp2TC2(c2);
			break;
		case EXP2_3:
			this->exp2TC3(c2);
			break;
		case EXP2_4:
			this->exp2TC4(c2);
			break;
		case EXP2_5:
			this->exp2TC5(c2);
			break;
		}


	Types exp2ResultType = c2->getTypes();
	node->setTypes(exp2ResultType);
	return exp2ResultType;
}

Types TypeCheck::exp2TC5(TreeNode* node) {
	TreeNode* c2 = (TreeNode*) node->getChildren()->getHead()->getNext()->getData();

	switch (c2->getNodeType()) {
		case EXP2:
			this->exp2TC(c2);
			break;
		case EXP2_2:
			this->exp2TC2(c2);
			break;
		case EXP2_3:
			this->exp2TC3(c2);
			break;
		case EXP2_4:
			this->exp2TC4(c2);
			break;
		case EXP2_5:
			this->exp2TC5(c2);
			break;
		}


	Types exp2ResultType = c2->getTypes();

	if(exp2ResultType != intType) {
		node->setTypes(errorType);
		return errorType;
	} else {
		node->setTypes(intType);
		return intType;
	}
}

Types TypeCheck::op_expTC(TreeNode* node) {
	TreeNode* c1 = (TreeNode*) node->getChildren()->getHead()->getData();

	if(c1->getNodeType() == EPSILON) {
		node->setTypes(noType);
		return noType;
	} else {
		TreeNode* c2 = (TreeNode*) node->getChildren()->getHead()->getNext()->getData();
		this->opTC(c1);
		this->expTC(c2);

		Types expResultType = c2->getTypes();
		node->setTypes(expResultType);
		return expResultType;
	}
}

Types TypeCheck::opTC(TreeNode* node) {
	LeafNode* c1 = (LeafNode*) node->getChildren()->getHead()->getData();

	switch (c1->getTerminal()) {
		case StateTypes::plusState:
			node->setTypes(opPlus);
			return opPlus;
		case StateTypes::minusState:
			node->setTypes(opMinus);
			return opMinus;
		case StateTypes::sternState:
			node->setTypes(opMult);
			return opMult;
		case StateTypes::doppelpunktState:
			node->setTypes(opDiv);
			return opDiv;
		case StateTypes::kleinerState:
			node->setTypes(opLess);
			return opLess;
		case StateTypes::groesserState:
			node->setTypes(opGreater);
			return opGreater;
		case StateTypes::gleichState:
			node->setTypes(opEqual);
			return opEqual;
		case StateTypes::gleichDoppelpunktGleichState:
			node->setTypes(opUnequal);
			return opUnequal;
		case StateTypes::undUndState:
			node->setTypes(opAnd);
			return opAnd;
		}
}
