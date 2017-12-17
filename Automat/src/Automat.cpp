/*
 * Automat.cpp
 *
 *  Created on: 02.11.2016
 *      Author: HanBu
 */
//#include "../includes/StateTypes.h"
#include "../includes/Automat.h"

/*
 * Konstruktor Automat
 * Definiert Finale Zustände und die Übergangsmatrix des Automats
 */
Automat::Automat() {

	this->keinKommentarScanner = true;
	currentState = StateTypes::startState;
	lastFinalState = StateTypes::undefinedState;
	stepsInState = 0;
	currentColumn = 1;
	currentLine = 1;
	tokenStartColumn = 1;
	tokenStartLine = 1;
	anzahlZustaende = (StateTypes::undefinedState) + 1;
	zeichen = 127;
	keinKommentar = true;

	//Finale Zustände festlegen
	isFinalState[StateTypes::startState] = false;
	isFinalState[StateTypes::integerState] = true;
	isFinalState[StateTypes::identifierState] = true;
	isFinalState[StateTypes::IFkleinState1] = true;
	isFinalState[StateTypes::IFkleinState2] = true;
	isFinalState[StateTypes::IFgrossState1] = true;
	isFinalState[StateTypes::IFgrossState2] = true;
	isFinalState[StateTypes::WHILEkleinState1] = true;
	isFinalState[StateTypes::WHILEkleinState2] = true;
	isFinalState[StateTypes::WHILEkleinState3] = true;
	isFinalState[StateTypes::WHILEkleinState4] = true;
	isFinalState[StateTypes::WHILEkleinState5] = true;
	isFinalState[StateTypes::WHILEgrossState1] = true;
	isFinalState[StateTypes::WHILEgrossState2] = true;
	isFinalState[StateTypes::WHILEgrossState3] = true;
	isFinalState[StateTypes::WHILEgrossState4] = true;
	isFinalState[StateTypes::WHILEgrossState5] = true;
	isFinalState[StateTypes::kommentarStartState] = true;
	isFinalState[StateTypes::kommentarEndeState] = true;
	isFinalState[StateTypes::plusState] = true;
	isFinalState[StateTypes::minusState] = true;
	isFinalState[StateTypes::sternState] = true;
	isFinalState[StateTypes::kleinerState] = true;
	isFinalState[StateTypes::groesserState] = true;
	isFinalState[StateTypes::gleichState] = true;
	isFinalState[StateTypes::doppelpunktState] = true;
	isFinalState[StateTypes::doppepunktGleichState] = true;
	isFinalState[StateTypes::gleichDoppelpunktState] = false;
	isFinalState[StateTypes::gleichDoppelpunktGleichState] = true;
	isFinalState[StateTypes::ausrufezeichenState] = true;
	isFinalState[StateTypes::semikolonState] = true;
	isFinalState[StateTypes::undState] = false;
	isFinalState[StateTypes::undUndState] = true;
	isFinalState[StateTypes::klammerAufState] = true;
	isFinalState[StateTypes::klammerZuState] = true;
	isFinalState[StateTypes::geschwKlammerAufState] = true;
	isFinalState[StateTypes::geschwKlammerZuState] = true;
	isFinalState[StateTypes::eckigeKlammerAufState] = true;
	isFinalState[StateTypes::eckigeKlammerZuState] = true;
	isFinalState[StateTypes::elseKleinState1] = true;
	isFinalState[StateTypes::elseKleinState2] = true;
	isFinalState[StateTypes::elseKleinState3] = true;
	isFinalState[StateTypes::elseKleinState4] = true;
	isFinalState[StateTypes::elseGrossState1] = true;
	isFinalState[StateTypes::elseGrossState2] = true;
	isFinalState[StateTypes::elseGrossState3] = true;
	isFinalState[StateTypes::elseGrossState4] = true;
	isFinalState[StateTypes::writeState2] = true;
	isFinalState[StateTypes::writeState3] = true;
	isFinalState[StateTypes::writeState4] = true;
	isFinalState[StateTypes::writeState5] = true;
	isFinalState[StateTypes::readState1] = true;
	isFinalState[StateTypes::readState2] = true;
	isFinalState[StateTypes::readState3] = true;
	isFinalState[StateTypes::readState4] = true;
	isFinalState[StateTypes::intState2] = true;
	isFinalState[StateTypes::intState3] = true;


	isFinalState[StateTypes::undefinedState] = false;

//Übergänge der Matrix mit undefined initialisieren
	for (int i = 0; i < anzahlZustaende; i++) {

		for (int j = 0; j < zeichen; j++) {
			stateMatrix[i][j] = StateTypes::undefinedState;
		}
	}

//Übergänge von startState

//Aufgabe2

	stateMatrix[StateTypes::startState]['r'] = StateTypes::readState1;


//
//Integer Initialisierung
	for (int i = '0'; i <= '9'; i++) {
		stateMatrix[StateTypes::startState][i] = StateTypes::integerState;
	}

//Identifier von a-d, f-h und A-D, F-H initialisieren
	for (int i = 'a'; i <= 'd'; i++) {
		stateMatrix[StateTypes::startState][i] = StateTypes::identifierState;
	}
	for (int i = 'A'; i <= 'D'; i++) {
		stateMatrix[StateTypes::startState][i] = StateTypes::identifierState;
	}

	stateMatrix[StateTypes::startState]['e'] = StateTypes::elseKleinState1;
	stateMatrix[StateTypes::startState]['E'] = StateTypes::elseGrossState1;

	for (int i = 'f'; i <= 'h'; i++) {
			stateMatrix[StateTypes::startState][i] = StateTypes::identifierState;
		}


	for (int i = 'F'; i <= 'H'; i++) {
			stateMatrix[StateTypes::startState][i] = StateTypes::identifierState;
		}

//IFklein1, für den Fall kleines i wird gelesen
	stateMatrix[StateTypes::startState]['i'] = StateTypes::IFkleinState1;
	//IFgross1, für den Fall großes I wird gelesen
	stateMatrix[StateTypes::startState]['I'] = StateTypes::IFgrossState1;

//Identifier von j-v und J-V initialisieren
	for (int i = 'j'; i <= 'q'; i++) {
		stateMatrix[StateTypes::startState][i] = StateTypes::identifierState;
	}

	stateMatrix[StateTypes::startState]['r'] = StateTypes::readState1;

	for (int i = 's'; i <= 'v'; i++) {
			stateMatrix[StateTypes::startState][i] = StateTypes::identifierState;
		}
	for (int i = 'J'; i <= 'V'; i++) {
		stateMatrix[StateTypes::startState][i] = StateTypes::identifierState;
	}

//WHILEklein1, für den Fall kleines w wird gelesen
	stateMatrix[StateTypes::startState]['w'] = StateTypes::WHILEkleinState1;
	//WHILEgross1, für den Fall großes W wird gelesen
	stateMatrix[StateTypes::startState]['W'] = StateTypes::WHILEgrossState1;

//Identitfier von x-z und X-Z initialisieren
	for (int i = 'x'; i <= 'z'; i++) {
		stateMatrix[StateTypes::startState][i] = StateTypes::identifierState;
	}
	for (int i = 'X'; i <= 'Z'; i++) {
		stateMatrix[StateTypes::startState][i] = StateTypes::identifierState;
	}
//Zeichen initialisieren
	stateMatrix[StateTypes::startState][' '] = StateTypes::startState;
	stateMatrix[StateTypes::startState]['\n'] = StateTypes::startState;
	stateMatrix[StateTypes::startState]['\t'] = StateTypes::startState;
	stateMatrix[StateTypes::startState]['+'] = StateTypes::plusState;
	stateMatrix[StateTypes::startState]['-'] = StateTypes::minusState;
	stateMatrix[StateTypes::startState]['*'] = StateTypes::sternState;
	stateMatrix[StateTypes::startState]['<'] = StateTypes::kleinerState;
	stateMatrix[StateTypes::startState]['>'] = StateTypes::groesserState;
	stateMatrix[StateTypes::startState]['='] = StateTypes::gleichState;
	stateMatrix[StateTypes::startState][':'] = StateTypes::doppelpunktState;
	stateMatrix[StateTypes::startState]['!'] = StateTypes::ausrufezeichenState;
	stateMatrix[StateTypes::startState][';'] = StateTypes::semikolonState;
	stateMatrix[StateTypes::startState]['&'] = StateTypes::undState;
	stateMatrix[StateTypes::startState]['('] = StateTypes::klammerAufState;
	stateMatrix[StateTypes::startState][')'] = StateTypes::klammerZuState;
	stateMatrix[StateTypes::startState]['{'] = StateTypes::geschwKlammerAufState;
	stateMatrix[StateTypes::startState]['}'] = StateTypes::geschwKlammerZuState;
	stateMatrix[StateTypes::startState]['['] = StateTypes::eckigeKlammerAufState;
	stateMatrix[StateTypes::startState][']'] = StateTypes::eckigeKlammerZuState;

//erlaubte Übergänge in integerState
	for (int i = '0'; i <= '9'; i++) {
		stateMatrix[StateTypes::integerState][i] = StateTypes::integerState;
	}

//erlaubte Übergänge in identifierState
	for (int i = 'a'; i <= 'z'; i++) {
		stateMatrix[StateTypes::identifierState][i] =
				StateTypes::identifierState;
	}
	for (int i = 'A'; i <= 'Z'; i++) {
		stateMatrix[StateTypes::identifierState][i] =
				StateTypes::identifierState;
	}
	for (int i = '0'; i <= '9'; i++) {
		stateMatrix[StateTypes::identifierState][i] =
				StateTypes::identifierState;
	}

//erlaubte Übergänge in ifKleinState1
	for (int i = 'a'; i <= 'e'; i++) {
		stateMatrix[StateTypes::IFkleinState1][i] = StateTypes::identifierState;
	}
	for (int i = 'g'; i <= 'm'; i++) {
		stateMatrix[StateTypes::IFkleinState1][i] = StateTypes::identifierState;
	}
	for (int i = 'o'; i <= 'z'; i++) {
			stateMatrix[StateTypes::IFkleinState1][i] = StateTypes::identifierState;
		}
	for (int i = 'A'; i <= 'Z'; i++) {
		stateMatrix[StateTypes::IFkleinState1][i] = StateTypes::identifierState;
	}
	for (int i = '0'; i <= '9'; i++) {
		stateMatrix[StateTypes::IFkleinState1][i] = StateTypes::identifierState;
	}
	stateMatrix[StateTypes::IFkleinState1]['f'] = StateTypes::IFkleinState2;

//erlaubte Übergänge in ifKleinState2
	for (int i = 'a'; i <= 'z'; i++) {
		stateMatrix[StateTypes::IFkleinState2][i] = StateTypes::identifierState;
	}
	for (int i = 'A'; i <= 'Z'; i++) {
		stateMatrix[StateTypes::IFkleinState2][i] = StateTypes::identifierState;
	}
	for (int i = '0'; i <= '9'; i++) {
		stateMatrix[StateTypes::IFkleinState2][i] = StateTypes::identifierState;
	}

//erlaubte Übergänge in ifGrossState1
	for (int i = 'A'; i <= 'E'; i++) {
		stateMatrix[StateTypes::IFgrossState1][i] = StateTypes::identifierState;
	}
	for (int i = 'G'; i <= 'Z'; i++) {
		stateMatrix[StateTypes::IFgrossState1][i] = StateTypes::identifierState;
	}
	for (int i = 'a'; i <= 'z'; i++) {
		stateMatrix[StateTypes::IFgrossState1][i] = StateTypes::identifierState;
	}

	for (int i = '0'; i <= '9'; i++) {
		stateMatrix[StateTypes::IFgrossState1][i] = StateTypes::identifierState;
	}
	stateMatrix[StateTypes::IFgrossState1]['F'] = StateTypes::IFkleinState2;

//erlaubte Übergänge in ifGrossState2
	for (int i = 'A'; i <= 'Z'; i++) {
		stateMatrix[StateTypes::IFgrossState2][i] = StateTypes::identifierState;
	}
	for (int i = 'a'; i <= 'z'; i++) {
		stateMatrix[StateTypes::IFgrossState2][i] = StateTypes::identifierState;
	}

	for (int i = '0'; i <= '9'; i++) {
		stateMatrix[StateTypes::IFgrossState2][i] = StateTypes::identifierState;
	}

//erlaubte Übergänge in whileKleinState1
	for (int i = 'a'; i <= 'g'; i++) {
		stateMatrix[StateTypes::WHILEkleinState1][i] =
				StateTypes::identifierState;
	}
	for (int i = 'i'; i <= 'q'; i++) {
		stateMatrix[StateTypes::WHILEkleinState1][i] =
				StateTypes::identifierState;
	}
	for (int i = 's'; i <= 'z'; i++) {
			stateMatrix[StateTypes::WHILEkleinState1][i] =
					StateTypes::identifierState;
		}
	for (int i = 'A'; i <= 'Z'; i++) {
		stateMatrix[StateTypes::WHILEkleinState1][i] =
				StateTypes::identifierState;
	}
	for (int i = '0'; i <= '9'; i++) {
		stateMatrix[StateTypes::WHILEkleinState1][i] =
				StateTypes::identifierState;
	}
	stateMatrix[StateTypes::WHILEkleinState1]['h'] =
			StateTypes::WHILEkleinState2;

//erlaubte Übergänge in whileKleinState2
	for (int i = 'a'; i <= 'h'; i++) {
		stateMatrix[StateTypes::WHILEkleinState2][i] =
				StateTypes::identifierState;
	}
	for (int i = 'j'; i <= 'z'; i++) {
		stateMatrix[StateTypes::WHILEkleinState2][i] =
				StateTypes::identifierState;
	}
	for (int i = 'A'; i <= 'Z'; i++) {
		stateMatrix[StateTypes::WHILEkleinState2][i] =
				StateTypes::identifierState;
	}
	for (int i = '0'; i <= '9'; i++) {
		stateMatrix[StateTypes::WHILEkleinState2][i] =
				StateTypes::identifierState;
	}
	stateMatrix[StateTypes::WHILEkleinState2]['i'] =
			StateTypes::WHILEkleinState3;

//erlaubte Übergänge in whileKleinState3
	for (int i = 'a'; i <= 'k'; i++) {
		stateMatrix[StateTypes::WHILEkleinState3][i] =
				StateTypes::identifierState;
	}
	for (int i = 'm'; i <= 'z'; i++) {
		stateMatrix[StateTypes::WHILEkleinState3][i] =
				StateTypes::identifierState;
	}
	for (int i = 'A'; i <= 'Z'; i++) {
		stateMatrix[StateTypes::WHILEkleinState3][i] =
				StateTypes::identifierState;
	}
	for (int i = '0'; i <= '9'; i++) {
		stateMatrix[StateTypes::WHILEkleinState3][i] =
				StateTypes::identifierState;
	}
	stateMatrix[StateTypes::WHILEkleinState3]['l'] =
			StateTypes::WHILEkleinState4;

//erlaubte Übergänge in whileKleinState4
	for (int i = 'a'; i <= 'd'; i++) {
		stateMatrix[StateTypes::WHILEkleinState4][i] =
				StateTypes::identifierState;
	}
	for (int i = 'f'; i <= 'z'; i++) {
		stateMatrix[StateTypes::WHILEkleinState4][i] =
				StateTypes::identifierState;
	}
	for (int i = 'A'; i <= 'Z'; i++) {
		stateMatrix[StateTypes::WHILEkleinState4][i] =
				StateTypes::identifierState;
	}
	for (int i = '0'; i <= '9'; i++) {
		stateMatrix[StateTypes::WHILEkleinState4][i] =
				StateTypes::identifierState;
	}
	stateMatrix[StateTypes::WHILEkleinState4]['e'] =
			StateTypes::WHILEkleinState5;

//erlaubte Übergänge in whileKleinState5
	for (int i = 'a'; i <= 'z'; i++) {
		stateMatrix[StateTypes::WHILEkleinState5][i] =
				StateTypes::identifierState;
	}
	for (int i = 'A'; i <= 'Z'; i++) {
		stateMatrix[StateTypes::WHILEkleinState5][i] =
				StateTypes::identifierState;
	}
	for (int i = '0'; i <= '9'; i++) {
		stateMatrix[StateTypes::WHILEkleinState5][i] =
				StateTypes::identifierState;
	}

//erlaubte Übergänge in whileGrossState1
	for (int i = 'A'; i <= 'G'; i++) {
		stateMatrix[StateTypes::WHILEgrossState1][i] =
				StateTypes::identifierState;
	}
	for (int i = 'I'; i <= 'Z'; i++) {
		stateMatrix[StateTypes::WHILEgrossState1][i] =
				StateTypes::identifierState;
	}
	for (int i = 'a'; i <= 'z'; i++) {
		stateMatrix[StateTypes::WHILEgrossState1][i] =
				StateTypes::identifierState;
	}
	for (int i = '0'; i <= '9'; i++) {
		stateMatrix[StateTypes::WHILEgrossState1][i] =
				StateTypes::identifierState;
	}
	stateMatrix[StateTypes::WHILEgrossState1]['H'] =
			StateTypes::WHILEgrossState2;

//erlaubte Übergänge in whileGrossState2
	for (int i = 'A'; i <= 'H'; i++) {
		stateMatrix[StateTypes::WHILEgrossState2][i] =
				StateTypes::identifierState;
	}
	for (int i = 'J'; i <= 'Z'; i++) {
		stateMatrix[StateTypes::WHILEgrossState2][i] =
				StateTypes::identifierState;
	}
	for (int i = 'a'; i <= 'z'; i++) {
		stateMatrix[StateTypes::WHILEgrossState2][i] =
				StateTypes::identifierState;
	}
	for (int i = '0'; i <= '9'; i++) {
		stateMatrix[StateTypes::WHILEgrossState2][i] =
				StateTypes::identifierState;
	}
	stateMatrix[StateTypes::WHILEgrossState2]['I'] =
			StateTypes::WHILEgrossState3;

//erlaubte Übergänge in whileGrossState3
	for (int i = 'A'; i <= 'K'; i++) {
		stateMatrix[StateTypes::WHILEgrossState3][i] =
				StateTypes::identifierState;
	}
	for (int i = 'M'; i <= 'Z'; i++) {
		stateMatrix[StateTypes::WHILEgrossState3][i] =
				StateTypes::identifierState;
	}
	for (int i = 'a'; i <= 'z'; i++) {
		stateMatrix[StateTypes::WHILEgrossState3][i] =
				StateTypes::identifierState;
	}
	for (int i = '0'; i <= '9'; i++) {
		stateMatrix[StateTypes::WHILEgrossState3][i] =
				StateTypes::identifierState;
	}
	stateMatrix[StateTypes::WHILEgrossState3]['L'] =
			StateTypes::WHILEgrossState4;

//erlaubte Übergänge in whileGrossState4
	for (int i = 'A'; i <= 'D'; i++) {
		stateMatrix[StateTypes::WHILEgrossState4][i] =
				StateTypes::identifierState;
	}
	for (int i = 'F'; i <= 'Z'; i++) {
		stateMatrix[StateTypes::WHILEgrossState4][i] =
				StateTypes::identifierState;
	}
	for (int i = 'a'; i <= 'z'; i++) {
		stateMatrix[StateTypes::WHILEgrossState4][i] =
				StateTypes::identifierState;
	}
	for (int i = '0'; i <= '9'; i++) {
		stateMatrix[StateTypes::WHILEgrossState4][i] =
				StateTypes::identifierState;
	}
	stateMatrix[StateTypes::WHILEgrossState4]['E'] =
			StateTypes::WHILEkleinState5;

//erlaubte Übergänge in whilegrossstate5
	for (int i = 'a'; i <= 'z'; i++) {
		stateMatrix[StateTypes::WHILEgrossState5][i] =
				StateTypes::identifierState;
	}
	for (int i = 'A'; i <= 'Z'; i++) {
		stateMatrix[StateTypes::WHILEgrossState5][i] =
				StateTypes::identifierState;
	}
	for (int i = '0'; i <= '9'; i++) {
		stateMatrix[StateTypes::WHILEgrossState5][i] =
				StateTypes::identifierState;
	}

//erlaubte übergänge in DoppelpunktState
	stateMatrix[StateTypes::doppelpunktState]['*'] =
			StateTypes::kommentarStartState;
	stateMatrix[StateTypes::doppelpunktState]['='] =
			StateTypes::doppepunktGleichState;

//erlaubte Übergang in gleichState
	stateMatrix[StateTypes::gleichState][':'] =
			StateTypes::gleichDoppelpunktState;

//erlaubte Übergang in gleichDoppelpunktState
	stateMatrix[StateTypes::gleichDoppelpunktState]['='] =
			StateTypes::gleichDoppelpunktGleichState;

//erlaubte Übergang in undState
	stateMatrix[StateTypes::undState]['&'] = StateTypes::undUndState;


//Aufgabe2

	//
	stateMatrix[StateTypes::WHILEkleinState1]['r'] =
					StateTypes::writeState2;
	//Übergänge für writeState2

	for (int i = 'a'; i <= 'h'; i++) {
			stateMatrix[StateTypes::writeState2][i] =
					StateTypes::identifierState;
	}
	for (int i = 'j'; i <= 'z'; i++) {
			stateMatrix[StateTypes::writeState2][i] =
					StateTypes::identifierState;
	}
	for (int i = 'A'; i <= 'Z'; i++) {
				stateMatrix[StateTypes::writeState2][i] =
						StateTypes::identifierState;
	}

	for (int i = '0'; i <= '9'; i++) {
				stateMatrix[StateTypes::writeState2][i] =
						StateTypes::identifierState;
	}
	stateMatrix[StateTypes::writeState2]['i'] =
						StateTypes::writeState3;

	//Übergänge writeState3
	for (int i = 'a'; i <= 's'; i++) {
				stateMatrix[StateTypes::writeState3][i] =
						StateTypes::identifierState;
		}
	for (int i = 'u'; i <= 'z'; i++) {
				stateMatrix[StateTypes::writeState3][i] =
						StateTypes::identifierState;
		}

	for (int i = 'A'; i <= 'Z'; i++) {
					stateMatrix[StateTypes::writeState3][i] =
							StateTypes::identifierState;
		}

	for (int i = '0'; i <= '9'; i++) {
					stateMatrix[StateTypes::writeState3][i] =
							StateTypes::identifierState;
		}

	stateMatrix[StateTypes::writeState3]['t'] =
							StateTypes::writeState4;

	//Übergänge writeState4
	for (int i = 'a'; i <= 'd'; i++) {
					stateMatrix[StateTypes::writeState4][i] =
							StateTypes::identifierState;
			}
		for (int i = 'f'; i <= 'z'; i++) {
					stateMatrix[StateTypes::writeState4][i] =
							StateTypes::identifierState;
			}

		for (int i = 'A'; i <= 'Z'; i++) {
						stateMatrix[StateTypes::writeState4][i] =
								StateTypes::identifierState;
			}

		for (int i = '0'; i <= '9'; i++) {
						stateMatrix[StateTypes::writeState4][i] =
								StateTypes::identifierState;
			}

		stateMatrix[StateTypes::writeState4]['e'] =
								StateTypes::writeState5;

	//Übergänge writeState5
		for (int i = 'A'; i <= 'Z'; i++) {
								stateMatrix[StateTypes::writeState5][i] =
										StateTypes::identifierState;
					}

		for (int i = '0'; i <= '9'; i++) {
								stateMatrix[StateTypes::writeState5][i] =
										StateTypes::identifierState;
					}

		for (int i = 'a'; i <= 'z'; i++) {
										stateMatrix[StateTypes::writeState5][i] =
												StateTypes::identifierState;
							}
	//Übergang IFkleinState1 (intState1)
		stateMatrix[StateTypes::IFkleinState1]['n'] = StateTypes::intState2;

	//Übergänge intState2

		for (int i = 'A'; i <= 'Z'; i++) {
										stateMatrix[StateTypes::intState2][i] =
												StateTypes::identifierState;
							}
		for (int i = '0'; i <= '9'; i++) {
										stateMatrix[StateTypes::intState2][i] =
												StateTypes::identifierState;
							}
		for (int i = 'a'; i <= 's'; i++) {
										stateMatrix[StateTypes::intState2][i] =
												StateTypes::identifierState;
							}
		for (int i = 'u'; i <= 'z'; i++) {
										stateMatrix[StateTypes::intState2][i] =
												StateTypes::identifierState;
							}

		stateMatrix[StateTypes::intState2]['t'] = StateTypes::intState3;

	//Übergänge intState3

		for (int i = 'A'; i <= 'Z'; i++) {
										stateMatrix[StateTypes::intState3][i] =
												StateTypes::identifierState;
							}
		for (int i = '0'; i <= '9'; i++) {
										stateMatrix[StateTypes::intState3][i] =
												StateTypes::identifierState;
							}
		for (int i = 'a'; i <= 'z'; i++) {
										stateMatrix[StateTypes::intState3][i] =
												StateTypes::identifierState;
							}

	//Übergänge readState1

		for (int i = 'A'; i <= 'Z'; i++) {
												stateMatrix[StateTypes::readState1][i] =
														StateTypes::identifierState;
									}
		for (int i = '0'; i <= '9'; i++) {
												stateMatrix[StateTypes::readState1][i] =
														StateTypes::identifierState;
									}

		for (int i = 'a'; i <= 'd'; i++) {
												stateMatrix[StateTypes::readState1][i] =
														StateTypes::identifierState;
									}
		for (int i = 'f'; i <= 'z'; i++) {
												stateMatrix[StateTypes::readState1][i] =
														StateTypes::identifierState;
									}

		stateMatrix[StateTypes::readState1]['e'] = StateTypes::readState2;

	//Übergänge readState2
		for (int i = 'A'; i <= 'Z'; i++) {
												stateMatrix[StateTypes::readState2][i] =
														StateTypes::identifierState;
									}
		for (int i = '0'; i <= '9'; i++) {
												stateMatrix[StateTypes::readState2][i] =
														StateTypes::identifierState;
									}
		for (int i = 'b'; i <= 'z'; i++) {
												stateMatrix[StateTypes::readState2][i] =
														StateTypes::identifierState;
									}

		stateMatrix[StateTypes::readState2]['a'] = StateTypes::readState3;

	//Übergänge readState3
		for (int i = 'A'; i <= 'Z'; i++) {
												stateMatrix[StateTypes::readState3][i] =
														StateTypes::identifierState;
									}
		for (int i = '0'; i <= '9'; i++) {
												stateMatrix[StateTypes::readState3][i] =
														StateTypes::identifierState;
									}
		for (int i = 'a'; i <= 'c'; i++) {
												stateMatrix[StateTypes::readState3][i] =
														StateTypes::identifierState;
									}
		for (int i = 'e'; i <= 'z'; i++) {
												stateMatrix[StateTypes::readState3][i] =
														StateTypes::identifierState;
									}

		stateMatrix[StateTypes::readState3]['d'] = StateTypes::readState4;

	//Übergänge readState4

		for (int i = 'A'; i <= 'Z'; i++) {
												stateMatrix[StateTypes::readState4][i] =
														StateTypes::identifierState;
									}
		for (int i = '0'; i <= '9'; i++) {
												stateMatrix[StateTypes::readState4][i] =
														StateTypes::identifierState;
									}
		for (int i = 'a'; i <= 'z'; i++) {
												stateMatrix[StateTypes::readState4][i] =
														StateTypes::identifierState;
									}

		//Übergänge ElseGroßState1
		for (int i = 'A'; i <= 'K'; i++) {
														stateMatrix[StateTypes::elseGrossState1][i] =
																StateTypes::identifierState;
											}
		stateMatrix[StateTypes::elseGrossState1]['L'] = StateTypes::elseGrossState2;

		for (int i = 'M'; i <= 'Z'; i++) {
																stateMatrix[StateTypes::elseGrossState1][i] =
																		StateTypes::identifierState;
													}

		for (int i = '0'; i <= '9'; i++) {
																stateMatrix[StateTypes::elseGrossState1][i] =
																		StateTypes::identifierState;
													}

		//Übergänge ElseGroßState2

		for (int i = 'A'; i <= 'R'; i++) {
																stateMatrix[StateTypes::elseGrossState2][i] =
																		StateTypes::identifierState;
													}
				stateMatrix[StateTypes::elseGrossState2]['S'] = StateTypes::elseGrossState3;

				for (int i = 'T'; i <= 'Z'; i++) {
																		stateMatrix[StateTypes::elseGrossState2][i] =
																				StateTypes::identifierState;
															}

				for (int i = '0'; i <= '9'; i++) {
																		stateMatrix[StateTypes::elseGrossState2][i] =
																				StateTypes::identifierState;
															}

		//Übergänge ElseGroßState3

		for (int i = 'A'; i <= 'D'; i++) {
																		stateMatrix[StateTypes::elseGrossState3][i] =
																				StateTypes::identifierState;
															}
						stateMatrix[StateTypes::elseGrossState3]['E'] = StateTypes::elseKleinState4;

						for (int i = 'F'; i <= 'Z'; i++) {
																				stateMatrix[StateTypes::elseGrossState3][i] =
																						StateTypes::identifierState;
																	}

						for (int i = '0'; i <= '9'; i++) {
																				stateMatrix[StateTypes::elseGrossState3][i] =
																						StateTypes::identifierState;
																	}

		//Übergänge ElseGroßState 4

						for (int i = 'A'; i <= 'Z'; i++) {
																				stateMatrix[StateTypes::elseGrossState4][i] =
																						StateTypes::identifierState;
																	}
						for (int i = '0'; i <= '9'; i++) {
																						stateMatrix[StateTypes::elseGrossState4][i] =
																								StateTypes::identifierState;
																			}
						//Übergänge ElseKleinState1
								for (int i = 'a'; i <= 'k'; i++) {
																				stateMatrix[StateTypes::elseKleinState1][i] =
																						StateTypes::identifierState;
																	}
								stateMatrix[StateTypes::elseKleinState1]['l'] = StateTypes::elseKleinState2;

								for (int i = 'm'; i <= 'z'; i++) {
																						stateMatrix[StateTypes::elseKleinState1][i] =
																								StateTypes::identifierState;
																			}

								for (int i = '0'; i <= '9'; i++) {
																						stateMatrix[StateTypes::elseKleinState1][i] =
																								StateTypes::identifierState;
																			}

								//Übergänge ElseKleinState2

								for (int i = 'a'; i <= 'r'; i++) {
																						stateMatrix[StateTypes::elseKleinState2][i] =
																								StateTypes::identifierState;
																			}
										stateMatrix[StateTypes::elseKleinState2]['s'] = StateTypes::elseKleinState3;

										for (int i = 't'; i <= 'z'; i++) {
																								stateMatrix[StateTypes::elseKleinState2][i] =
																										StateTypes::identifierState;
																					}

										for (int i = '0'; i <= '9'; i++) {
																								stateMatrix[StateTypes::elseKleinState2][i] =
																										StateTypes::identifierState;
																					}

								//Übergänge ElseGroßState3

								for (int i = 'a'; i <= 'd'; i++) {
																								stateMatrix[StateTypes::elseKleinState3][i] =
																										StateTypes::identifierState;
																					}
												stateMatrix[StateTypes::elseKleinState3]['e'] = StateTypes::elseKleinState4;

												for (int i = 'f'; i <= 'z'; i++) {
																										stateMatrix[StateTypes::elseKleinState3][i] =
																												StateTypes::identifierState;
																							}

												for (int i = '0'; i <= '9'; i++) {
																										stateMatrix[StateTypes::elseKleinState3][i] =
																												StateTypes::identifierState;
																							}

								//Übergänge ElseKleinState 4

												for (int i = 'a'; i <= 'z'; i++) {
																										stateMatrix[StateTypes::elseKleinState4][i] =
																												StateTypes::identifierState;
																							}
												for (int i = '0'; i <= '9'; i++) {
																												stateMatrix[StateTypes::elseKleinState4][i] =
																														StateTypes::identifierState;
																									}
}
Automat::~Automat() {
}
bool Automat::checkChar(char c) {

//Darf weiter verarbeitet werden?
	bool weiter = true;

//Wenn Token neu beginnt Column und Line aktualisieren
	if (currentState == StateTypes::startState) {
		if (c == (char) '\n') {
			currentLine += 1;
			currentColumn = 1;
			weiter = true;
		} else if (c == '\t') {
			currentColumn += 1;
			weiter = true;
		} else {
			tokenStartColumn = currentColumn;
			tokenStartLine = currentLine;
			currentState = stateMatrix[currentState][c];
			currentColumn += 1;

//lastFinalState updaten;
			if (currentState != StateTypes::undefinedState) {
				if (isFinalState[currentState]) {
					lastFinalState = currentState;
				}
				weiter = true;
			}
//bei undefiniertem Zustand abbrechen
			else {
				weiter = false;
			}
		}
		return weiter;
	} else if (currentState == StateTypes::undState && c != (char) '&') {
		cout << "Fehler  Line: " << currentLine << "  Column: "
				<< currentColumn - 1 << "  Zeichen: &" << endl;
	}
//bei Absatz aktuellen Zustand verwenden, auch wenn undefined
	else if (c == (char) '\n') {
		//im Kommentar
		if (!keinKommentar) {
			currentState = StateTypes::kommentarStartState;
			lastFinalState = currentState;
			currentColumn = 1;
			currentLine += 1;
			return false;
		}
		currentColumn = 1;
		currentLine += 1;
		if (!isFinalState[currentState]) {
			lastFinalState = StateTypes::undefinedState;
		} else {
			lastFinalState = currentState;
		}

		currentState = StateTypes::startState;
		return false;
	}
//bei Leerzeichen Token abschließen
	if (c == (char) ' ') {
		if (!keinKommentar) {
			currentState = StateTypes::kommentarStartState;
			lastFinalState = currentState;
			currentColumn += 1;
			return false;
		}
		if (currentState != StateTypes::startState) {
			if (!isFinalState[currentState]) {
				currentColumn += 1;
				lastFinalState = StateTypes::undefinedState;
			} else {
				currentColumn += 1;
				lastFinalState = currentState;
			}
			currentState = StateTypes::startState;
			weiter = false;
		} else {
			currentColumn += 1;
			weiter = true;
		}
		return weiter;
	}
//bei Tabulator aktuellen Zustand verwenden, auch wenn undefined
	else if (c == (char) '\t') {
		if (!keinKommentar) {
			currentState = StateTypes::kommentarStartState;
			lastFinalState = currentState;
			currentColumn += 1;
			return false;
		}
		currentColumn += 1;
		if (!isFinalState[currentState]) {
			lastFinalState = StateTypes::undefinedState;
		} else {
			lastFinalState = currentState;
		}
		currentState = StateTypes::startState;
		return false;
	}

//erkennt Anfang eines Kommentars
	else if (currentState == StateTypes::doppelpunktState && c == (char) '*') {
		keinKommentar = false;
		this->keinKommentarScanner = keinKommentar;
		currentState = StateTypes::kommentarStartState;
		lastFinalState = currentState;
		currentColumn += 1;
		return true;
	}

	else if (currentState == StateTypes::kommentarStartState && keinKommentar) {
		currentColumn += 1;
		return true;
	}

//erkennt im Kommentar Ende *
	else if (!keinKommentar) {
		currentColumn += 1;
		if (c == (char) '*') {
			currentState = StateTypes::sternState;
			weiter = true;
		} else if (currentState == StateTypes::sternState && c == (char) ':') {
			keinKommentar = true;
			this->keinKommentarScanner = keinKommentar;
			lastFinalState = StateTypes::kommentarEndeState;
			currentState = StateTypes::startState;
			weiter = false;
		}
		return weiter;
	}

	//für normale Eingaben
	else {
		currentState = stateMatrix[currentState][c];
		if (isFinalState[currentState]) {
			currentColumn += 1;
			lastFinalState = currentState;
			weiter = true;
		} else if (currentState != StateTypes::undefinedState) {
			currentColumn += 1;
			weiter = true;
		} else {
			currentState = StateTypes::startState;
			weiter = false;
		}
		return weiter;

	}
	return false;

}

/*
 * Getter Methoden
 */
int Automat::getColumn() {
	return tokenStartColumn;
}

int Automat::getErrorColumn() {
	return currentColumn;
}

int Automat::getLine() {
	return tokenStartLine;
}
int Automat::getErrorLine() {
	return currentLine;
}

bool Automat::getKeinKommentarScanner() {
	return this->keinKommentarScanner;
}

StateTypes::State Automat::getLastFinalState() {
	return lastFinalState;
}
