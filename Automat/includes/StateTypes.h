/*
 * StateTypes.h
 *
 *  Created on: Dec 6, 2016
 *      Author: hele1015
 */

#ifndef AUTOMAT_INCLUDES_STATETYPES_H_
#define AUTOMAT_INCLUDES_STATETYPES_H_

/*
 * States die der Automat annehmen kann. Ist kein Zustand definiert wird der Zustand UndefinedState angenommen.
 */
class StateTypes {
public:
	enum  State {
	startState,
	integerState,
	identifierState,

	IFkleinState1,
	IFkleinState2,

	IFgrossState1,
	IFgrossState2,

	WHILEkleinState1,//w
	WHILEkleinState2,//h
	WHILEkleinState3,//i
	WHILEkleinState4,//l
	WHILEkleinState5,//e

	WHILEgrossState1,
	WHILEgrossState2,
	WHILEgrossState3,
	WHILEgrossState4,
	WHILEgrossState5,

	kommentarStartState,
	kommentarEndeState,

	plusState,
	minusState,

	sternState,
	kleinerState,
	groesserState,

	gleichState,
	doppelpunktState,
	doppepunktGleichState,
	gleichDoppelpunktState,
	gleichDoppelpunktGleichState,

	ausrufezeichenState,
	semikolonState,

	undState,
	undUndState,

	klammerAufState,
	klammerZuState,
	geschwKlammerAufState,
	geschwKlammerZuState,
	eckigeKlammerAufState,
	eckigeKlammerZuState,

	//Aufgabe 2
	elseKleinState1,
	elseKleinState2,
	elseKleinState3,
	elseKleinState4,

	elseGrossState1,
	elseGrossState2,
	elseGrossState3,
	elseGrossState4,

	//whileKlein1
	writeState2,
	writeState3,
	writeState4,
	writeState5,

	readState1,
	readState2,
	readState3,
	readState4,

	//ifKlein1
	intState2,
	intState3,



	//else, ELSE, write, read, int
	//weitere Zustände ÜBER undefined eintragen
	undefinedState,

};
};

#endif /* AUTOMAT_INCLUDES_STATETYPES_H_ */
