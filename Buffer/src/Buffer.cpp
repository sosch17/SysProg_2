/*
 * Buffer.cpp
 *
 *  Created on:
 *      Author: Gruppe MJL
 */

#include "../includes/Buffer.h"

// /home/stud/lkt/fbi/hele1015/workspace/sysProg-master/Test.txt

/**
 * Der Konstruktor erstellt die beiden Arrays.
 */
Buffer::Buffer(int size, char* input ) {
	offset = 0; 			//Position in der Datei
	position = -1;			//Position im Buffer
	arrayLength = size;
	currentChar = new char[arrayLength]; // Buffer 1
	previousChar = new char[arrayLength];// Buffer 2
	inputTxt = input;
	loadNewChars();
	this->endOfFile = endOfFile;
}

Buffer::~Buffer() {
	delete currentChar;
	delete previousChar;
}

/**
 * Läd das momentane Array (Buffer1) mit neuen Werten und verschiebt
 * die vorherigen Werte in das andere Array(Buffer2).
 */
void Buffer::loadNewChars() {

	int k = 0;
	int temp = 0;


//Buffer 2 "freimachen"
	for(int i=0; i < arrayLength; i++){
			previousChar[i] = '\0';
	}

//Alle Werte aus Buffer 2 in Buffer 1 transportieren
	for(int i=0; i < arrayLength; i++){
			previousChar[i] = currentChar[i];
			currentChar[i] = '\0';
	}

//Datei öffnen
	FILE* datei;
	datei = fopen (inputTxt, "r");
	//"r"	read: Open file for input operations. The file must exist.

   // char text[arrayLength+1];
    if (datei != NULL){
		 //fscanf (datei, "%100c", text);

    	fseek(datei,offset,SEEK_SET);
    	temp = fgetc(datei);
    	while((temp != EOF) && (k < arrayLength)){
    		//printf("%d\n",offset);
    		//printf("%c\n",temp);
    		currentChar[k] = temp;
    		k++;
    		temp = fgetc(datei);
    		offset++;
    	}
//    	if(temp == EOF) {
//    		cout << "EOF" << endl;
//    		this->endOfFile = true;
//    	}
		//currentChar[arrayLength - 1] = '\0';

		//printf ("%s\n", text);
		fclose (datei);
    }else {
    	printf("Datei nicht gefunden\n");
	}


}

/*
 * lädt das alte Array in das aktuelle Array
 * (um immer nur vom aktuellen Array zu lesen)
 */

void Buffer::loadOldChars() {

	for(int i=0; i < arrayLength; i++){
		currentChar[i] = previousChar[i];
	}
}

/**
 * Gibt das nächste Zeichen zurück,
 *  wenn es keins mehr gibt, wird NULL zurück gegeben.
 */
char Buffer::getNextChar() {
	if (position + 1 < arrayLength) {
		position++;
	} else {
		loadNewChars();
		position = 0;
	}
	if(currentChar[position]!= '\0'){
		return currentChar[position];
	} else {
		this->endOfFile = true;
		return '\0';
	}
}

/**
 * setzt das letzte herraus gegebene Zeichen auf "position"
 */
void Buffer::setChar() {
	if (position >= 0) {
		position--;
	} else {
		loadOldChars();
		position = arrayLength - 2;
	}
}

void Buffer::setChar2() {
	if (position + 1 >= 0) {
		position -= 2;
	} else {
		loadOldChars();
		position = arrayLength - 1;
	}
}

//BSP: Ausgabe:"12_34"
// Gibt "4" aus
char Buffer::getLastListedChar(){
	setChar();
	return getNextChar();
}

//BSP: Ausgabe:"12_34"
// Gibt "3" aus
char Buffer::getPreviousChar(){
	setChar2();
	return getNextChar();
}

bool Buffer::getEndOfFile() {
	return this->endOfFile;
}

