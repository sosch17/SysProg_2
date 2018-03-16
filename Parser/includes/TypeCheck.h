/*
 * TypeCheck.h
 *
 *  Created on: now
 *      Author: hele1015
 */

#ifndef TypeCheck_H_
#define TypeCheck_H_

#include "./ParseTree.h"
#include <iostream>
#include <fstream>
using namespace std;


class TypeCheck {
public:
	TypeCheck(ParseTree* tree);
	//BasicNode* getCurrentNode();
private:
	ParseTree* tree;
	BasicNode* currentNode;
	TreeNode* root;
	bool hasError;
	Types progTC(TreeNode* node);
	Types declsTC(TreeNode* node);
	//Types declsTC2(TreeNode* node);
	Types declTC(TreeNode* node);
	Types arrayTC(TreeNode* node);
	//Types arrayTC2(TreeNode* node);
	Types statementsTC(TreeNode* node);
	//Types statementsTC2(TreeNode* node);
	Types statementTC(TreeNode* node);
	Types statementTC2(TreeNode* node);
	Types statementTC3(TreeNode* node);
	Types statementTC4(TreeNode* node);
	Types statementTC5(TreeNode* node);
	Types statementTC6(TreeNode* node);
	Types expTC(TreeNode* node);
	Types exp2TC(TreeNode* node);
	Types exp2TC2(TreeNode* node);
	Types exp2TC3(TreeNode* node);
	Types exp2TC4(TreeNode* node);
	Types exp2TC5(TreeNode* node);
	Types indexTC(TreeNode* node);
	//Types indexTC2(TreeNode* node);
	Types op_expTC(TreeNode* node);
	//Types op_expTC2(TreeNode* node);
	Types opTC(TreeNode* node);
//	Types opTC2(TreeNode* node);
//	Types opTC3(TreeNode* node);
//	Types opTC4(TreeNode* node);
//	Types opTC5(TreeNode* node);
//	Types opTC6(TreeNode* node);
//	Types opTC7(TreeNode* node);
//	Types opTC8(TreeNode* node);
//	Types opTC9(TreeNode* node);

};

#endif /* TypeCheck_H_ */
