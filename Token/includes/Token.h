/*
 * Token.h
 *
 *  Created on: 03.12.2016
 *      Author: descb
 */

#ifndef TOKEN_H_
#define TOKEN_H_
#include <stdlib.h>
#include <stdio.h>
#include "../../Symboltable/includes/LinkedList.h"
#include "../../Automat/includes/Automat.h"
#include "../../Symboltable/includes/SymTabEntry.h"

class Token {
public:
	Token(StateTypes::State iD, char* content, int myline, int mycolumn);
	virtual ~Token();
	StateTypes::State getName();
	char* getContent();
	int getContentInt();
	int getLine();
	int getColumn();
	Node<SymTabEntry>* getKey();
	void setKey(Node<SymTabEntry>* myKey);

private:
	StateTypes::State iD;
	char* content;
	int contentInt;
	int line;
	int column;
	Node<SymTabEntry>* key;
};

#endif /* TOKEN_H_ */
