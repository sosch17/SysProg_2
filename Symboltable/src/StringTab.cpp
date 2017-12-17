/*
 * StringTab.cpp
 *
 *  Created on: 2016
 *      Author: hele1015
 */

#include "../includes/StringTab.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

/*
 * StringTab speichert alle Lexeme in einem char Array. Sobald dieses voll ist erweitert sich die String Tabelle automatisch.
 */
StringTab::StringTab() {
	this->freespace = tablesize;
	table = new char[tablesize];
	this->freeP = table;
	firstElement = table;
	//cout << "Init" << endl;
}

/*
 * Destruktor
 */
StringTab::~StringTab() {
	delete[] this->freeP;
}

/*
 * Fügt ein neues Lexem mit einer bestimmten Länge der StringTable hinzu und gibt den aktuellen Pointer auf das Element zurück
 * Param: char* lexem, int size
 * Return: char* temp
 */
char* StringTab::insert(char* lexem, int size){
	char* temp = this->freeP;
	if(size < this->freespace){
		memcpy(this->freeP, lexem, size + 1);
		this->freeP[size] = '\0';
		this->freeP += size + 1;
		this->freespace -= size + 1;
	}
		else{
			freespace = tablesize;
			resize(tablesize);
			return insert(lexem, size);
		}
	return temp;
}

/*
 * Allokiert mehr Speicher, falls nicht mehr genügend Speicher für das Lexem vorhanden ist.
 * Param: int n
 */
void StringTab::resize(int n){
	char* resized = new char[n]();
	freeP = resized;
}


