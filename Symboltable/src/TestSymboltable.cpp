#include "../includes/Symboltable.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

	Symboltable* symboltable;
	symboltable = new Symboltable();

	cout << symboltable->hash("Hallo") << endl;
	cout << symboltable->hash("15") << endl;
	cout << symboltable->hash("=") << endl;
	cout << symboltable->hash("Katze") << endl;
	cout << symboltable->hash("+") << endl;
	cout << symboltable->hash("Berg") << endl;

	//LinkedList Test mit Arraylänge 5
	cout << symboltable->insert("Hallo", 5) << endl;;
	cout << symboltable->insert("15", 2) << endl;
	cout << symboltable->insert("=", 1, "Gleich") << endl;
	cout << symboltable->insert("Katze", 5) << endl;
	cout << symboltable->insert("+", 5, "Plus") << endl;
	cout << symboltable->insert("Berg", 4) << endl;

	//lookUp sollte NULL sein
	cout << symboltable->insert("Hallo", 5) << endl;
	cout << symboltable->insert("15", 2) << endl;

	//cout << "Katze bereits da? " << symboltable->lookup("Katze") << endl;
	//cout << "Hallo bereits da? " << symboltable->lookup("Hallo") << endl;
	//cout << "Turm bereits da? " << symboltable->lookup("Turm") << endl;
	//cout << " '' bereits da? " << symboltable->lookup("") << endl;

}
