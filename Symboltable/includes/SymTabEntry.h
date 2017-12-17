/*
 * SymTabEntry.h
 *
 *  Created on: 2016
 *      Author: hele1015
 */

#ifndef SYMTABENTRY_H_
#define SYMTABENTRY_H_


class SymTabEntry {
public:
	SymTabEntry(char* myName, char* type);
	virtual ~SymTabEntry();
	char* getName();
	char* getType();
	bool compareLexem(char* lexem);

private:
	char* name;
	char* type;

};

#endif /* SYMTABENTRY_H_ */
