
#include "../includes/StringTab.h"
#include <iostream>
using namespace std;


int main(int argc, char **argv) {

	StringTab* strT = new StringTab();

	char* erg1 = strT->insert("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26);
	char* erg2 = strT->insert("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26);
	char* erg3 = strT->insert("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26);
	char* erg4 = strT->insert("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26);

}
