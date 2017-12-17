/*
 * Token.cpp
 *
 *  Created on: 03.12.2016
 *      Author: descb
 */

#include "../includes/Token.h"

//=================================================================================
//			Erstellt einen neuen Token
//=================================================================================
/*
 * Konstruktor
 * Params: State name, char* content, int line, int column
 */
Token::Token(StateTypes::State name, char* myContent, int myline, int mycolumn) {
	this->iD = name;
	this->content = myContent;
	this->contentInt = 0;
	this->line = myline;
	this->column = mycolumn;
	this->key = '\0';

	/*Die folgenden Verzweigungen prüfen, ob der Integer-Bereich Überschritten wird
	 *WENN JA -> wird aus dem IntegerToken ein StateTypes::undefinedState
	 */

	if(name == StateTypes::integerState){
		this->contentInt = strtol(myContent, NULL, 10);
	}

	if(this->contentInt == -1){
		this->iD = StateTypes::undefinedState;
		cout << "Fehler" << "  Line: " << line << "  Column: " << column - 1
				<< " Zahl ist zu lang!" << endl;
	}
}

Token::~Token() {
	// TODO Auto-generated destructor stub
}

//=================================================================================
//			Token Getter
//=================================================================================

StateTypes::State Token::getName() {
	return this->iD;
}

char* Token::getContent() {
	return this->content;
}

int Token::getContentInt() {
	return this->contentInt;
}

int Token::getLine() {
	return this->line;
}

int Token::getColumn() {
	return this->column;
}

SymTabEntry* Token::getKey() {
	return this->key;
}

void Token::setKey(SymTabEntry* myKey) {
	this->key = myKey;
}

