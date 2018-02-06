/*
 * Tree.h
 *
 *  Created on: now
 *      Author: hele1015
 */

#ifndef Tree_H_
#define Tree_H_

#include "../../Scanner/includes/Scanner.h"
#include "../../Token/includes/Token.h"
#include "./NodeTypes.h"
#include "../../Symboltable/includes/LinkedList.h"
#include <iostream>
#include <fstream>
using namespace std;

class TreeNode;

class BasicNode {
public:
	BasicNode();
	// für TypeCheck
	Types getTypes();
	void setTypes(Types t);
	bool isLeaf();
	void setLeaf(bool leaf);

private:
	Types type;
	bool leaf;
};

class TreeNode : public BasicNode {
public:
	TreeNode(TreeNode* parent, NodeTypes type);
	TreeNode();
	NodeTypes getNodeType();
	TreeNode* getParent();
	LinkedList<BasicNode>* getChildren();

	private:
	TreeNode* parent;
	NodeTypes nodeType;
	LinkedList<BasicNode>* children;
};

class LeafNode : public BasicNode {
public:
	LeafNode(TreeNode* parent, StateTypes::State terminal, Token* token);
	StateTypes::State getTerminal();
	Token* getToken();
	TreeNode* getParent();

	private:
	TreeNode* parent;
	StateTypes::State terminal;
	Token* token;
};

class ParseTree {
private:

	Scanner* scanner;
	Token* currentToken;
	//Tree tree;
	TreeNode* root;

public:
	ParseTree(Scanner* scanner);
	TreeNode* getRoot();
	LeafNode* addLeaf(TreeNode* parent, StateTypes::State terminal, Token* token);
	TreeNode* addNode(TreeNode* parent, NodeTypes type);
	Token getCurrentToken();
	bool isReachableTerminal(Token* token, NodeTypes type);
	void prog(TreeNode* parent);
	void decls(TreeNode* parent);
	void decl(TreeNode* parent);
	void array(TreeNode* parent);
	void statements(TreeNode* parent);
	void statement(TreeNode* parent);
	void exp(TreeNode* parent);
	void exp2(TreeNode* parent);
	void index(TreeNode* parent);
	void op_exp(TreeNode* parent);
	void op(TreeNode* parent);
	void error();
	void checkTokenType(StateTypes::State stateType);
};


#endif /* Tree_H_ */
