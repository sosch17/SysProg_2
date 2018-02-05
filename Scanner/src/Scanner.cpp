/*
 * Scanner.cpp
 *
 *  Created on: Dez 3, 2016
 *
 */
#include "../includes/Scanner.h"
//=================================================================================
//			Scanner
//=================================================================================
/*
 * Konstruktor
 */
Scanner::Scanner(char* input) {
	arrayLength = 1024;
	buffer = new Buffer(arrayLength, input);	//Buffer erzeugen
	temporaryChars = new char[arrayLength];
	tokenChar = new char[arrayLength];
//da um chars für einen Token abzuspeichern
	resetTemporaryChars();	//löschen um Platz für das nächste Token zu haben
	position = 0;								//Pos. im temporaryChars

	automat = new Automat();
	symboltable = new Symboltable();
	OutputBuffer* output = new OutputBuffer();

	wordSize = 0;
	eofChar = 'a';
}

/*
 * Destruktor
 */
Scanner::~Scanner() {
	delete buffer;
	delete temporaryChars;
	delete automat;
	delete symboltable;
}

//=================================================================================
//			Scanner
//=================================================================================
/*
 * Holt sich aus dem Buffer nach und nach Chars schickt sie in den Automaten und bildet so Tokens.
 * Fehler werden als Leerzeichen an den Automaten übergeben.
 * Return: Adresse auf Token
 */
Token* Scanner::getNextToken() {

	resetTemporaryChars(); //loesche wenn evtl befuellt
	bool automatTestChar;

	//Schicke Chars in den Automaten bis es ein State erkennt
	do {

		textchar = buffer->getNextChar();
		if (automat->getKeinKommentarScanner() && textchar != 0
				&& textchar != '\n' && textchar != 32 && textchar != 13
				&& textchar != '\t' && textchar != ' ' && textchar != 33
				&& textchar != 38 && textchar != 40 && textchar != 41
				&& textchar != 42 && textchar != 43 && textchar != 45
				&& (textchar < 48 || textchar > 62)
				&& (textchar < 65 || textchar > 91) && textchar != 93
				&& (textchar < 97 || textchar > 123) && textchar != 125) {
			char tempChar = textchar;
			textchar = (char) ' ';
			automatTestChar = automat->checkChar(textchar);
			cout << "Fehler" << "  Line: " << automat->getErrorLine()
					<< "  Column: " << automat->getErrorColumn() - 1
					<< "  Zeichen: " << tempChar << endl;
		} else {
			automatTestChar = automat->checkChar(textchar);
		}

		eofChar = textchar;

//		Soll keine Leerzeichen usw. in das Token speichern!
//		Keine Kommentare speichern!
		if (textchar != ' ' && textchar != (char) '\t'
				&& textchar != (char) '\n'
				&& automat->getKeinKommentarScanner()) {
			//Fuellt CharArray mit Chars um den Namen im Token abzuspeichern
			temporaryChars[position] = textchar;
			position++;
			wordSize++;
		}
	} while (automatTestChar);

	// falls keine Leerzeichentrennung zwischen while+ zb.
	if (textchar != '\0' && textchar != (char) '\t' && textchar != (char) '\n'
			&& textchar != (char) ' ' && automat->getKeinKommentarScanner()
			&& automat->getLastFinalState() != 17
			&& automat->getLastFinalState() != 18
			//&& automat->kommEnde
					) {
		textchar = buffer->getPreviousChar();
		wordSize--;
	}

	//Befuelle das Token
	StateTypes::State state = automat->getLastFinalState();

	//falls im zustand eines unvollständigen while oder if mache state zu identifier
	if (state == 3 || state == 5 || (state >= 7 && state <= 10)
			|| (state >= 12 && state <= 15)) {
		state = StateTypes::identifierState;
	}

	int line = automat->getLine();
	int column = automat->getColumn();  // - 1;

	for (int i = 0; i < wordSize; i++) {
		tokenChar[i] = temporaryChars[i];
	}

	return createToken(state, line, column);
}

//=================================================================================
//			Erstellt das naechste Token.
//=================================================================================
/*
 *createToken erstellt ein Token aus übergebenen Parametern und schreibt Identifier in die Symboltabelle.
 *Key aus der Symboltabelle wird ebenfalls im Token gespeichert.
 * Params: State state, int line, int column
 * Return: Adresse auf Token
 */
Token* Scanner::createToken(StateTypes::State state, int line, int column) {
	Token* token;
	Node<SymTabEntry>* key = '\0';

	if (eofChar == '\0') {
		lastchar = buffer->getPreviousChar();
		if (lastchar != '\n' && lastchar != ' ' && lastchar != '\t') {
			token = new Token(state, tokenChar, line, column);
			return token;
		} else {
			return NULL;
		}

	}

	if (state == StateTypes::identifierState) {
		key = symboltable->insert(tokenChar, wordSize);
	}

	token = new Token(state, tokenChar, line, column);
//	cout << "setKey:  " << key << endl;
	token->setKey(key);
	resetTemporaryChars();
	//WordSize fuer naechsten Token auf null setzen!
	wordSize = 0;
	return token;
}

//=================================================================================
//			Setzt alle Werte im Array auf NULL.
//=================================================================================

/**
 * leert temporaryChar und tokenChar für neues Wort.
 */
void Scanner::resetTemporaryChars() {
	temporaryChars = new char[arrayLength];
	for (int i = 0; i < arrayLength; i++) {
		temporaryChars[i] = '\0';
	}
	tokenChar = new char[arrayLength];
	for (int i = 0; i < arrayLength; i++) {
		tokenChar[i] = '\0';
	}
	position = 0;
}

bool Scanner::isEndOfFile() {
	return eofChar == (char)'\0';
}

