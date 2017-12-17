/*
 * Scanner.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include "../../Token/includes/Token.h"
#include "../../Buffer/includes/Buffer.h"
#include "../../Automat/includes/Automat.h"
#include "../../Symboltable/includes/Symboltable.h"
#include "../includes/OutputBuffer.h"
#include <iostream>
#include <fstream>
using namespace std;


class Scanner {
public:
	Scanner(char* input); // Bekommt die Datei
	virtual ~Scanner();
	Token* getNextToken();
	Symboltable* getSymboltable();
	OutputBuffer* output;
	bool isEndOfFile();
	char eofChar;

private:
	char* temporaryChars;
	void resetTemporaryChars();
	Token* createToken(StateTypes::State state, int line, int column);
	// NEU! ! ! ! ! !
	Token* createToken();
	int wordSize; // fuer die Symboltabelle

	Automat* automat;
	Buffer* buffer;
	int position;
	int arrayLength;
	Symboltable* symboltable;
	char* tokenChar;
	char textchar;

	char lastchar;

};

#endif /* SCANNER_H_ */
