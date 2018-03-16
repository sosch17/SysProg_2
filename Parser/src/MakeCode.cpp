#include "../includes/MakeCode.h"

MakeCode::MakeCode(ParseTree* tree, ofstream* file){
	this->code = file;
	if ( !(*this->code).is_open())
	    {
	        cerr << "error opening file";
	    }
	this->labelcnt = 0;
	this->tree = tree;
	this->progMC(this->tree->getRoot());
	(*this->code).close();
}

void MakeCode::progMC(TreeNode* node) {

		TreeNode* c1 = (TreeNode*) node->getChildren()->getHead()->getData();
		TreeNode* c2 =
						(TreeNode*) node->getChildren()->getHead()->getNext()->getData();

		this->declsMC(c1);
		this->statementsMC(c2);

		(*this->code) << "STP "<< flush;

}

void MakeCode::declsMC(TreeNode* node) {
	TreeNode* c1 = (TreeNode*) node->getChildren()->getHead()->getData();

	if(c1->getNodeType() != EPSILON) {
		TreeNode* c3 =
						(TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getData();
		this->declMC(c1);
		this->declsMC(c3);
	}
}

void MakeCode::declMC(TreeNode* node) {
	TreeNode* c2 =
			(TreeNode*) node->getChildren()->getHead()->getNext()->getData();
	LeafNode* c3 =
			(LeafNode*) node->getChildren()->getHead()->getNext()->getNext()->getData();

	(*this->code) << "DS "<< "$"<< c3->getToken()->getContent() << " " << flush;
	this->arrayMC(c2);

}
void MakeCode::arrayMC(TreeNode* node) {
	BasicNode* c1 = node->getChildren()->getHead()->getData();
	if(c1->isLeaf())
	{
		LeafNode* c2 = (LeafNode*) node->getChildren()->getHead()->getNext()->getData();
		(*this->code) << ""<< c2->getToken()->getContentInt() << flush << endl;
	}
	else{
		(*this->code) << ""<< 1 << flush << endl;
	}

}
void MakeCode::statementsMC(TreeNode* node) {
	TreeNode* c1 = (TreeNode*) node->getChildren()->getHead()->getData();

		if(c1->getNodeType() != EPSILON) {
			TreeNode* c3 = (TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getData();

			switch (c1->getNodeType()) {
			case STATEMENT:
				this->statementMC(c1);
				break;
			case STATEMENT2:
				this->statementMC2(c1);
				break;
			case STATEMENT3:
				this->statementMC3(c1);
				break;
			case STATEMENT4:
				this->statementMC4(c1);
				break;
			case STATEMENT5:
				this->statementMC5(c1);
				break;
			case STATEMENT6:
				this->statementMC6(c1);
				break;
			}

			this->statementsMC(c3);
		}
}
void MakeCode::statementMC(TreeNode* node) {
	LeafNode* c1 = (LeafNode*) node->getChildren()->getHead()->getData();
		TreeNode* c2 =
				(TreeNode*) node->getChildren()->getHead()->getNext()->getData();
		TreeNode* c4 =
				(TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getNext()->getData();
	this->expMC(c4);
	(*this->code) << "LA "<< "$"<< c1->getToken()->getContent() << flush << endl;
	this->indexMC(c2);
	(*this->code) << "STR "<< flush << endl;

}
void MakeCode::statementMC2(TreeNode* node) {
	TreeNode* c3 = (TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getData();
	this->expMC(c3);
	(*this->code) << "PRI "<< flush << endl;

}
void MakeCode::statementMC3(TreeNode* node) {
	LeafNode* c3 =
				(LeafNode*) node->getChildren()->getHead()->getNext()->getNext()->getData();
	TreeNode* c4 =
				(TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getNext()->getData();

	(*this->code) << "REA "<< flush << endl;
	(*this->code) << "LA "<< "$"<< c3->getToken()->getContent() << flush << endl;
	this->indexMC(c4);
	(*this->code) << "STR "<< flush << endl;

}
void MakeCode::statementMC4(TreeNode* node) {
	TreeNode* c2 =
			(TreeNode*) node->getChildren()->getHead()->getNext()->getData();

	this->statementsMC(c2);

}
void MakeCode::statementMC5(TreeNode* node) {
	int label = this->labelcnt;
	this->labelcnt++;
	int label2 = this->labelcnt;
	this->labelcnt++;
	TreeNode* c3 =
			(TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getData();
	TreeNode* c5 =
			(TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getNext()->getNext()->getData();
	TreeNode* c7 =
			(TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->getData();

	this->expMC(c3);
	(*this->code) << "JIN "<< "#" << "label" << label << " " << flush << endl; // label1 ist neu
	switch (c5->getNodeType()) {
	case STATEMENT:
		this->statementMC(c5);
		break;
	case STATEMENT2:
		this->statementMC2(c5);
		break;
	case STATEMENT3:
		this->statementMC3(c5);
		break;
	case STATEMENT4:
		this->statementMC4(c5);
		break;
	case STATEMENT5:
		this->statementMC5(c5);
		break;
	case STATEMENT6:
		this->statementMC6(c5);
		break;
	}
	(*this->code) << "JMP "<< "#" << "label" << label2 << " " << flush << endl; // label2 ist neu
	(*this->code) << "#" << "label" << label << " "<< "NOP "<< flush << endl;
	switch (c7->getNodeType()) {
	case STATEMENT:
		this->statementMC(c7);
		break;
	case STATEMENT2:
		this->statementMC2(c7);
		break;
	case STATEMENT3:
		this->statementMC3(c7);
		break;
	case STATEMENT4:
		this->statementMC4(c7);
		break;
	case STATEMENT5:
		this->statementMC5(c7);
		break;
	case STATEMENT6:
		this->statementMC6(c7);
		break;
	}
	(*this->code) << "#" << "label" << label2 << " " << "NOP "<< flush << endl;

}
void MakeCode::statementMC6(TreeNode* node) {
	int label = this->labelcnt;
	this->labelcnt++;
	int label2 = this->labelcnt;
	this->labelcnt++;
	TreeNode* c3 =
			(TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getData();
	TreeNode* c5 =
			(TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getNext()->getNext()->getData();
	(*this->code) << "#"<< "label" << label << " " << "NOP "<< flush << endl;

	this->expMC(c3);

	(*this->code) << "JIN "<< "#" << "label" << label2 << " " << flush << endl;

	switch (c5->getNodeType()) {
	case STATEMENT:
		this->statementMC(c5);
		break;
	case STATEMENT2:
		this->statementMC2(c5);
		break;
	case STATEMENT3:
		this->statementMC3(c5);
		break;
	case STATEMENT4:
		this->statementMC4(c5);
		break;
	case STATEMENT5:
		this->statementMC5(c5);
		break;
	case STATEMENT6:
		this->statementMC6(c5);
		break;
	}

	(*this->code) << "JMP "<< "#"<< "label" << label << " " << flush << endl;
	(*this->code) << "#"<< "label" << label2 << " " << "NOP "<< flush << endl;

}
void MakeCode::expMC(TreeNode* node) {
	TreeNode* c1 = (TreeNode*) node->getChildren()->getHead()->getData();
	TreeNode* c2 = (TreeNode*) node->getChildren()->getHead()->getNext()->getData();

	if(c2->getChildren()->getHead()->getData()->getTypes() == opGreater) {
		this->op_expMC(c2);
		switch (c1->getNodeType()) {
			case EXP2:
				this->exp2MC(c1);
				break;
			case EXP2_2:
				this->exp2MC2(c1);
				break;
			case EXP2_3:
				this->exp2MC3(c1);
				break;
			case EXP2_4:
				this->exp2MC4(c1);
				break;
			case EXP2_5:
				this->exp2MC5(c1);
				break;
			}
		(*this->code) << "LES"<< flush << endl;
	} else if(c2->getChildren()->getHead()->getData()->getTypes() == opUnequal) {

		switch (c1->getNodeType()) {
			case EXP2:
				this->exp2MC(c1);
				break;
			case EXP2_2:
				this->exp2MC2(c1);
				break;
			case EXP2_3:
				this->exp2MC3(c1);
				break;
			case EXP2_4:
				this->exp2MC4(c1);
				break;
			case EXP2_5:
				this->exp2MC5(c1);
				break;
			}
		this->op_expMC(c2);
		(*this->code) << "NOT"<< flush << endl;
	} else {
		switch (c1->getNodeType()) {
			case EXP2:
				this->exp2MC(c1);
				break;
			case EXP2_2:
				this->exp2MC2(c1);
				break;
			case EXP2_3:
				this->exp2MC3(c1);
				break;
			case EXP2_4:
				this->exp2MC4(c1);
				break;
			case EXP2_5:
				this->exp2MC5(c1);
				break;
			}
		if(c2->getTypes() != noType) {
			this->op_expMC(c2);
		}
	}

//	this->op_expMC(c2);

}
void MakeCode::exp2MC(TreeNode* node) {
	TreeNode* c2 = (TreeNode*) node->getChildren()->getHead()->getNext()->getData();

	this->expMC(c2);
}
void MakeCode::exp2MC2(TreeNode* node) {
	LeafNode* c1 = (LeafNode*) node->getChildren()->getHead()->getData();

	(*this->code) << "LA "<< "$"<< c1->getToken()->getContent() << flush << endl;

	if(node->getChildren()->getHead()->getNext() != NULL) {
		TreeNode* c2 = (TreeNode*) node->getChildren()->getHead()->getNext()->getData();
		this->indexMC(c2);
		}
	(*this->code) << "LV "<< flush << endl;
}
void MakeCode::exp2MC3(TreeNode* node) {
	LeafNode* c1 = (LeafNode*) node->getChildren()->getHead()->getData();
	(*this->code) << "LC "<< c1->getToken()->getContentInt() << flush << endl;
}
void MakeCode::exp2MC4(TreeNode* node) {
	TreeNode* c2 = (TreeNode*) node->getChildren()->getHead()->getNext()->getData();
	(*this->code) << "LC "<< 0 << flush << endl;
			switch (c2->getNodeType()) {
				case EXP2:
					this->exp2MC(c2);
					break;
				case EXP2_2:
					this->exp2MC2(c2);
					break;
				case EXP2_3:
					this->exp2MC3(c2);
					break;
				case EXP2_4:
					this->exp2MC4(c2);
					break;
				case EXP2_5:
					this->exp2MC5(c2);
					break;
				}
	(*this->code) << "SUB "<< flush << endl;
}
void MakeCode::exp2MC5(TreeNode* node) {
	TreeNode* c2 = (TreeNode*) node->getChildren()->getHead()->getNext()->getData();

		switch (c2->getNodeType()) {
			case EXP2:
				this->exp2MC(c2);
				break;
			case EXP2_2:
				this->exp2MC2(c2);
				break;
			case EXP2_3:
				this->exp2MC3(c2);
				break;
			case EXP2_4:
				this->exp2MC4(c2);
				break;
			case EXP2_5:
				this->exp2MC5(c2);
				break;
			}
		(*this->code) << "NOT "<< flush << endl;
}
void MakeCode::indexMC(TreeNode* node) {
	BasicNode* c1 = node->getChildren()->getHead()->getData();

	if (c1->isLeaf() == true) {  //EPSILON
		TreeNode* c2 = (TreeNode*) node->getChildren()->getHead()->getNext()->getData();

		this->expMC(c2);
		(*this->code) << "ADD "<< flush << endl;
	}


}
void MakeCode::op_expMC(TreeNode* node) {
	TreeNode* c1 = (TreeNode*) node->getChildren()->getHead()->getData();

		if(c1->getNodeType() != EPSILON) {
			TreeNode* c2 = (TreeNode*) node->getChildren()->getHead()->getNext()->getData();
			this->expMC(c2);
			this->opMC(c1);

		}
}
void MakeCode::opMC(TreeNode* node) {
	LeafNode* c1 = (LeafNode*) node->getChildren()->getHead()->getData();

	switch (c1->getTerminal()) {
		case StateTypes::plusState:
			(*this->code) << "ADD"<< flush << endl;
			break;
		case StateTypes::minusState:
			(*this->code) << "SUB"<< flush << endl;
			break;
		case StateTypes::sternState:
			(*this->code) << "MUL"<< flush << endl;
			break;
		case StateTypes::doppelpunktState:
			(*this->code) << "DIV"<< flush << endl;
			break;
		case StateTypes::kleinerState:
			(*this->code) << "LES"<< flush << endl;
			break;
		case StateTypes::groesserState:
			break;
		case StateTypes::gleichState:
			(*this->code) << "EQU"<< flush << endl;
			break;
		case StateTypes::gleichDoppelpunktGleichState:
			(*this->code) << "EQU"<< flush << endl;
			break;
		case StateTypes::undUndState:
			(*this->code) << "AND"<< flush << endl;
			break;
		}

}
