/*
 * OutputBuffer.h
 *
 *  Created on: 2016
 *      Author: hele1015
 */

#ifndef OUTPUTBUFFER_H_
#define OUTPUTBUFFER_H_

#include "../../Token/includes/Token.h"
#include <iostream>
#include <fstream>
using namespace std;

class OutputBuffer {
public:
	OutputBuffer();
	virtual ~OutputBuffer();
	void writeInFile(Token* t, ofstream* file);
	void writeFailure(Token* t);
	char* switchIntToState(int i);

};

#endif /* OUTPUTBUFFER_H_ */
