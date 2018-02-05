/*
 * Symboltable.cpp
 *
 *  Created on: 2016
 *      Author: hele1015
 */
#include "../includes/Symboltable.h"
#include <iostream>
using namespace std;

/*
 * Konstruktor
 */
Symboltable::Symboltable() {

	this->hashTable = new LinkedList<SymTabEntry> [512];
	// initialisiert eine StringTab.
	this->strT = strT;
	this->initSymbols();

}

/*
 * Destruktor
 */
Symboltable::~Symboltable() {
	delete[] this->hashTable;
	delete strT;
}

/*
 * Fügt Schlüsselworte direkt in die Symboltabelle ein mit entsprechendem Typ.
 */
void Symboltable::initSymbols() {
	this->insert("while", 5, "while");
	this->insert("WHILE", 5, "while");
	this->insert("if", 5, "if");
	this->insert("IF", 5, "if");
	this->insert("else", 4, "else");
	this->insert("ELSE", 4, "else");
	this->insert("int", 3, "int");
	this->insert("read", 4, "read");
	this->insert("write", 5, "write");
}

/*
 * Fügt lexem in die HashMap ein, an der Stelle der gehashten Schlüssels.
 * Param: char* lexem
 * Return: SymTabEntry* eintragsAdresse
 */
Node<SymTabEntry>* Symboltable::insert(char* lexem, int size, char* type) {
	Node<SymTabEntry>* lookupValue = this->lookup(lexem);
	if (lookupValue == NULL) {
		long key = this->hash(lexem);
		char* posInStringTab = this->strT->insert(lexem, size); // Referenz auf Stelle in StringTab
		SymTabEntry* entry = new SymTabEntry(posInStringTab, "Identifier");
		if (this->hashTable[key].isEmpty() == false) {

			return this->hashTable[key].addNode(entry);
			//wenn schon Einträge bestehen
//			return entry;

		} else {
			return this->hashTable[key].initNode(entry);
//			return entry;
		}
	} else {
		return lookupValue;
	}
}

/*
 * Hasht das Lexem um einen Key für die Hashmap zu erhalten.
 * Param: char* lexem
 * Return: unsigned long hashwert
 */
unsigned long Symboltable::hash(char* lexem) {
	long precision = 3;
	unsigned long hash = 0;
	while (*lexem) {
		hash += (*(unsigned long*) lexem) >> precision;
		lexem++;
	}
//    while (*lexem)
//        hash = (hash * 22) + *lexem++ - '0';
//	hash = hash % 1024;
	hash = hash % 512;
	return hash;
}
/*
 * Gibt true oder false zurück je nachdem ob das lexem gefunden wurde oder nicht
 * Param: char* lexem
 * return: SymTabEntry* adresseDesGefunden
 */
Node<SymTabEntry>* Symboltable::lookup(char* lexem) {
	unsigned long key = this->hash(lexem);

	if (this->hashTable[key].isEmpty() == true) {
		return NULL;
	} else {
		Node<SymTabEntry>* pos = this->hashTable[key].getHead();
		if (pos->getNext() == NULL) {
			if (pos->getData()->compareLexem(lexem) == true) {
				return pos;
			} else {
				return NULL;
			}
		}
		while (pos->getNext() != NULL) {
			if (pos->getData()->compareLexem(lexem) == true) {
				return pos;
			} else {
				pos = pos->getNext();
			}
		}
		if (pos->getNext() == NULL) {
			if (pos->getData()->compareLexem(lexem) == true) {
				return pos;
			} else {
				return NULL;
			}
		}
	}
	return NULL;
}
