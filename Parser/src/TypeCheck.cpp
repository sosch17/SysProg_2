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
	TreeNode* c1 = (TreeNode*)node->getChildren()->getHead()->getData();
	if(c1->getNodeType() != EPSILON) {
		this->declsTC(c1);
	}

	node->setTypes(noType); // eigentlich egal da default noType
	// statements
}

Types TypeCheck::declsTC(TreeNode* node) {
	TreeNode* c1 = (TreeNode*)node->getChildren()->getHead()->getData();
	TreeNode* c3 = (TreeNode*)node->getChildren()->getHead()->getNext()->getNext()->getData();
	this->declTC(c1);
	this->declsTC(c3);
}


Types TypeCheck::declTC(TreeNode* node) {
	TreeNode* c2 = (TreeNode*)node->getChildren()->getHead()->getNext()->getData();
	LeafNode* c3 = (LeafNode*)node->getChildren()->getHead()->getNext()->getNext()->getData();
	this->arrayTC(c2);
	if(c3->getToken()->getKey()->getType() != "Identifier") {
		cout << "identifier already defined. Error in Line - " << c3->getToken()->getLine() << "  Column - " << c3->getToken()->getColumn() << endl;
		return errorType;
	} else if () {

	}
}

Types TypeCheck::arrayTC(TreeNode* node) {

}

Types TypeCheck::arrayTC2(TreeNode* node) {

}


















