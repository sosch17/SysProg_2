/*
 * SymTabEntry.cpp
 *
 *  Created on: 2016
 *      Author: hele1015
 */

#include "../includes/SymTabEntry.h"
#include <iostream>
using namespace std;

/*
 * Konstruktor.
 * Param: char* myName
 */
SymTabEntry::SymTabEntry(char* myName, char* myType){
	name = myName;
	type = myType;
	this->dimention = 1;
}

/*
 * Destruktor
 */
SymTabEntry::~SymTabEntry() {
	delete [] this->name;
}

/*
 * Gibt Name des Eintrags zurück.
 * Return: char* name
 */
char* SymTabEntry::getName() {
	return name;
}

/*
 * Gibt Typ des Eintrags zurück.
 * Return: char* type
 */
char* SymTabEntry::getType() {
	return type;
}

/*
 * Setzt Typ des Eintrags.
 */
void SymTabEntry::setType(char* type) {
	this->type = type;
}

/*
 * Gibt Typ des Eintrags zurück.
 * Return: char* type
 */
int SymTabEntry::getDimention() {
	return this->dimention;
}

/*
 * Setzt Typ des Eintrags.
 */
void SymTabEntry::setDimention(int d) {
	this->type = type;
}



/*
 * Vergleicht ein mitgegebenes lexem mit dem Namen des Eintrags.
 * Param: char* lexem
 * Return: boolean obLexemGleichIst
 */
bool SymTabEntry::compareLexem(char* lexem) {
	char* ptr = lexem;
	char* ptr2 = name;
	while (*ptr == *ptr2) {
		ptr++;
		ptr2++;
		if(*ptr == '\0' && *ptr2 == '\0') {
			return true;
		}
	}
	return false;
}
