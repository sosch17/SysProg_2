#include "StateTypes.h"
#include <iostream>
using namespace std;

#ifndef AUTOMAT_H_
#define AUTOMAT_H_

class Automat{
private:
StateTypes::State currentState;
StateTypes::State lastFinalState;
int stepsInState;
int currentColumn;
int currentLine;
int tokenStartColumn;
int tokenStartLine;
int zeichen;
//für checkChar
//befinde ich mich in einem Kommentar
bool keinKommentar;
bool keinKommentarScanner;

//Matrix
bool isFinalState [(StateTypes::undefinedState) +1];
StateTypes::State stateMatrix[(StateTypes::undefinedState) +1][127];
bool useChar(char* c);

//Undefined IMMER letzter Zustand
//undefined +1
int anzahlZustaende;

public:
Automat();
~Automat();
int getColumn();
int getLine();
int getErrorColumn();
int getErrorLine();
bool getKeinKommentarScanner();
StateTypes::State getLastFinalState();
bool checkChar(char c);
};

#endif /* AUTOMAT_H_ */
