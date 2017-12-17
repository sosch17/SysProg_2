/*
 * OutputBuffer.cpp
 *
 *  Created on: 2016
 *      Author: hele1015
 *      */

#include "../includes/OutputBuffer.h"
#include <iostream>
#include <fstream>
using namespace std;

/*
 * Konstruktor
 * Param: int myTokenMax (Wie viele Token sollen gemeinsam in die Datei geschrieben werden
 * 		  char* myUrl (Zielurl für die out.txt Datei.
 */
OutputBuffer::OutputBuffer() {

}

/*
 * Destruktor
 */
OutputBuffer::~OutputBuffer() {
}

/*
 * Bereitet die Informationen aus den Tokens auf um sie in das File zu schreiben.
 * Params: Token* t, ofstream file
 */
void OutputBuffer::writeInFile(Token* t, ofstream* file) {
	if (this->switchIntToState(t->getName()) == "Integer") {
		(*file) << "Token: " << this->switchIntToState(t->getName())
				<< "  Line: " << t->getLine() << "  Column: " << t->getColumn()
				<< "  Value: " << t->getContentInt() << endl;
	} else if (this->switchIntToState(t->getName()) == "Identifier") {
		(*file) << "Token: " << this->switchIntToState(t->getName())
				<< "  Line: " << t->getLine() << "  Column: " << t->getColumn()
				<< "  Lexem: " << t->getContent() << endl;
	} else if (this->switchIntToState(t->getName()) == "KommentarStart"
			|| this->switchIntToState(t->getName()) == "KommentarEnde"
			|| this->switchIntToState(t->getName()) == "UndefinedFehler") {
	} else {
		(*file) << "Token: " << this->switchIntToState(t->getName())
				<< "  Line: " << t->getLine() << "  Column: " << t->getColumn()
				<< endl;
	}
}

/*
 * Nimmt States als Int entgegen und bereitet sie für die Ausgabe in Strings auf.
 * Params: int i
 */
char* OutputBuffer::switchIntToState(int i) {
	char* state;
	switch (i) {
	case 1:
		state = "Integer";
		break;
	case 2:
		state = "Identifier";
		break;
	case 4:
		state = "IfKlein";
		break;
	case 6:
		state = "IfGross";
		break;
	case 11:
		state = "WhileKlein";
		break;
	case 16:
		state = "WhileGross";
		break;
	case 17:
		state = "KommentarStart";
		break;
	case 18:
		state = "KommentarEnde";
		break;
	case 19:
		state = "Plus";
		break;
	case 20:
		state = "Minus";
		break;
	case 21:
		state = "Stern";
		break;
	case 22:
		state = "Kleiner";
		break;
	case 23:
		state = "Groesser";
		break;
	case 24:
		state = "Gleich";
		break;
	case 25:
		state = "Doppelpunkt";
		break;
	case 26:
		state = "DoppelpunktGleich";
		break;
	case 27:
		state = "GleichDoppelpunkt";
		break;
	case 28:
		state = "GleichDoppelpunktGleich";
		break;
	case 29:
		state = "Ausrufezeichen";
		break;
	case 30:
		state = "Semicolon";
		break;
	case 31:
		state = "Und";
		break;
	case 32:
		state = "UndUnd";
		break;
	case 33:
		state = "KlammerAuf";
		break;
	case 34:
		state = "KlammerZu";
		break;
	case 35:
		state = "GeschwKlammerAuf";
		break;
	case 36:
		state = "GeschwKlammerZu";
		break;
	case 37:
		state = "EckigeKlammerAuf";
		break;
	case 38:
		state = "EckigeKlammerZu";
		break;
	case 39:
		state = "UndefinedFehler";
		break;
	default:
		state = "";
		break;
	}
	return state;
}

