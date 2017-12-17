/*
 * Buffer.h
 *
 *  Created on:
 *      Author: Gruppe : Melina Johanna Leonie
 */

#ifndef BUFFER_H_
#define BUFFER_H_
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

class Buffer {
public:
	Buffer(int size, char* input);
	virtual ~Buffer();
	char getNextChar();
	char getPreviousChar();
	char getLastListedChar();
	void setChar();
	void setChar2();
	void loadNewChars();
	bool getEndOfFile();
	int offset;            // Stelle in der Datei
private:
	char* currentChar;
	char* previousChar;
	int position;         // aktuelle Stelle im Buffer
	int arrayLength;
	char* inputTxt;
	bool endOfFile;


	void loadOldChars();

};

#endif /* BUFFER_H_ */
