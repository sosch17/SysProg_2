/*
 * Symboltable.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include "SymTabEntry.h"
#include "LinkedList.h"
#include "StringTab.h"

class Symboltable {
public:
	Symboltable();
	virtual ~Symboltable();
	void initSymbols();
	Node<SymTabEntry>* insert(char* lexem, int size, char* type = "Identifier");
	Node<SymTabEntry>* lookup(char* lexem);
	unsigned long hash(char* lexem);

private:
	LinkedList<SymTabEntry>* hashTable;
	StringTab* strT = new StringTab();
};

#endif /* SYMBOLTABLE_H_ */
