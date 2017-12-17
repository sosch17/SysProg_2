/*
 * StringTab.h
 *
 *  Created on: 2016
 *      Author: hele1015
 */

#ifndef STRINGTAB_H_
#define STRINGTAB_H_

class StringTab {
public:
	StringTab();
	virtual ~StringTab();
	char* insert(char* lexem, int size);


private:
	char* freeP;
	int freespace;
	void resize(int n);
	int tablesize = 1024;
	char* table;
	char* firstElement;
};

#endif /* STRINGTAB_H_ */
