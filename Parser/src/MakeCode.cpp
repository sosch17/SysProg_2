#include "../includes/MakeCode.h"

MakeCode::MakeCode(ParseTree* tree){
	ofstream code("/home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/out.txt");
	if ( !code.is_open())
	    {
	        cerr << "error opening file";
	    }
	this->code << "Start";
	this->labelcnt = 0;
	this->tree = tree;
	this->progMC(this->tree->getRoot());
}

void MakeCode::progMC(TreeNode* node) {
//	if(node->getChildren()->getHead()->getData() != NULL) {
//			TreeNode* c1 = (TreeNode*) node->getChildren()->getHead()->getData();
//			if (c1->getNodeType() != EPSILON) {
//				this->declsMC(c1);
//			}
//			if(node->getChildren()->getHead()->getNext()->getData() != NULL) {
//				TreeNode* c2 =
//						(TreeNode*) node->getChildren()->getHead()->getNext()->getData();
//				if(c2->getNodeType() != EPSILON) {
//					this->statementsMC(c2);
//				}
//			}
//		}
	cout << "progMC" << endl;

		TreeNode* c1 = (TreeNode*) node->getChildren()->getHead()->getData();
		TreeNode* c2 =
						(TreeNode*) node->getChildren()->getHead()->getNext()->getData();

		this->declsMC(c1);
		this->statementsMC(c2);


	code << " STP ";
	this->code.close();

}
void MakeCode::declsMC(TreeNode* node) {
	TreeNode* c1 = (TreeNode*) node->getChildren()->getHead()->getData();
	TreeNode* c3 =
			(TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getData();

	if(c1->getNodeType() != EPSILON) {
		this->declMC(c1);
		this->declsMC(c3);
	}
}
void MakeCode::declMC(TreeNode* node) {
	TreeNode* c2 =
			(TreeNode*) node->getChildren()->getHead()->getNext()->getData();
	LeafNode* c3 =
			(LeafNode*) node->getChildren()->getHead()->getNext()->getNext()->getData();

	code << " DS " << "$" << c3->getToken()->getContent();
	this->arrayMC(c2);

}
void MakeCode::arrayMC(TreeNode* node) {
	BasicNode* c1 = node->getChildren()->getHead()->getData();
	if(c1->isLeaf())
	{
		LeafNode* c2 = (LeafNode*) node->getChildren()->getHead()->getNext()->getData();
		code << c2->getToken()->getContentInt();
	}
	else{
		code << 1;
	}

}
void MakeCode::statementsMC(TreeNode* node) {
	TreeNode* c1 = (TreeNode*) node->getChildren()->getHead()->getData();

		if(c1->getNodeType() == EPSILON) {
			code << " NOP ";
		} else {
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
	code << " LA " << "$" << c1->getToken()->getContent();
	this->indexMC(c2);
	code << " STR ";

}
void MakeCode::statementMC2(TreeNode* node) {
	TreeNode* c3 = (TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getData();
	this->expMC(c3);
	code << " PRI ";

}
void MakeCode::statementMC3(TreeNode* node) {
	LeafNode* c3 =
				(LeafNode*) node->getChildren()->getHead()->getNext()->getNext()->getData();
	TreeNode* c4 =
				(TreeNode*) node->getChildren()->getHead()->getNext()->getNext()->getNext()->getData();

	code << " REA ";
	code << " LA " << "$" << c3->getToken()->getContent();
	this->indexMC(c4);
	code << " STR ";

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
	code << " JIN " << "#" << label; // label1 ist neu
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
	code << " JMP " << "#" << label2; // label2 ist neu
	code << "#" << label << " NOP ";
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
	code << "#" << label2 << " NOP ";

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
	code << "#" << label << " NOP ";

	this->expMC(c3);

	code << " JIN " << "#" << label2;

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

	code << " JMP " << "#" << label;
	code << "#" << label2 << " NOP ";

}
void MakeCode::expMC(TreeNode* node) {
	TreeNode* c1 = (TreeNode*) node->getChildren()->getHead()->getData();
	TreeNode* c2 = (TreeNode*) node->getChildren()->getHead()->getNext()->getData();

	if(c2->getTypes() == noType) {
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
	} else if(c2->getChildren()->getHead()->getData()->getTypes() == opGreater) {
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
		code << "LES";
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
		code << "NOT";
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
		this->op_expMC(c2);
	}



	this->op_expMC(c2);

}
void MakeCode::exp2MC(TreeNode* node) {
	TreeNode* c2 = (TreeNode*) node->getChildren()->getHead()->getNext()->getData();

	this->expMC(c2);
}
void MakeCode::exp2MC2(TreeNode* node) {
	LeafNode* c1 = (LeafNode*) node->getChildren()->getHead()->getData();
	TreeNode* c2 = (TreeNode*) node->getChildren()->getHead()->getNext()->getData();
	code << " LA " << "$" << c1->getToken()->getContent();
	this->indexMC(c2);
	code << " LV ";
}
void MakeCode::exp2MC3(TreeNode* node) {
	LeafNode* c1 = (LeafNode*) node->getChildren()->getHead()->getData();
	code << " LC " << c1->getToken()->getContentInt();
}
void MakeCode::exp2MC4(TreeNode* node) {
	TreeNode* c2 = (TreeNode*) node->getChildren()->getHead()->getNext()->getData();
	code << " LC " << 0;
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
	code << " SUB ";
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
		code << " NOT ";
}
void MakeCode::indexMC(TreeNode* node) {
	BasicNode* c1 = node->getChildren()->getHead()->getData();

	if (c1->isLeaf() == true) {  //EPSILON
		TreeNode* c2 = (TreeNode*) node->getChildren()->getHead()->getNext()->getData();

		this->expMC(c2);
		code << " ADD ";
	}


}
void MakeCode::op_expMC(TreeNode* node) {
	TreeNode* c1 = (TreeNode*) node->getChildren()->getHead()->getData();

		if(c1->getNodeType() != EPSILON) {
			TreeNode* c2 = (TreeNode*) node->getChildren()->getHead()->getNext()->getData();
			this->opMC(c1);
			this->expMC(c2);
		}
}
void MakeCode::opMC(TreeNode* node) {
	LeafNode* c1 = (LeafNode*) node->getChildren()->getHead()->getData();

	switch (c1->getTerminal()) {
		case StateTypes::plusState:
			code << "ADD";
			break;
		case StateTypes::minusState:
			code << "SUB";
			break;
		case StateTypes::sternState:
			code << "MUL";
			break;
		case StateTypes::doppelpunktState:
			code << "DIV";
			break;
		case StateTypes::kleinerState:
			code << "LES";
			break;
		case StateTypes::groesserState:
			break;
		case StateTypes::gleichState:
			code << "EQU";
			break;
		case StateTypes::gleichDoppelpunktGleichState:
			code << "EQU";
			break;
		case StateTypes::undUndState:
			code << "AND";
			break;
		}

}
