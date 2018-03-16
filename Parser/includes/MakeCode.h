/*
 * MakeCode.h
 *
 *  Created on: 31.01.2018
 *      Author: leonie
 */

#ifndef MAKECODE_H_
#define MAKECODE_H_

#include "./ParseTree.h"

class MakeCode {

private:
	ofstream code;
	int labelcnt;
	ParseTree* tree;

public:
	MakeCode(ParseTree* tree);

	void progMC(TreeNode* node);
	void declsMC(TreeNode* node);
	void declMC(TreeNode* node);
	void arrayMC(TreeNode* node);
	void statementsMC(TreeNode* node);
	void statementMC(TreeNode* node);
	void statementMC2(TreeNode* node);
	void statementMC3(TreeNode* node);
	void statementMC4(TreeNode* node);
	void statementMC5(TreeNode* node);
	void statementMC6(TreeNode* node);
	void expMC(TreeNode* node);
	void exp2MC(TreeNode* node);
	void exp2MC2(TreeNode* node);
	void exp2MC3(TreeNode* node);
	void exp2MC4(TreeNode* node);
	void exp2MC5(TreeNode* node);
	void indexMC(TreeNode* node);
	void op_expMC(TreeNode* node);
	void opMC(TreeNode* node);

};

#endif /* MAKECODE_H_ */
