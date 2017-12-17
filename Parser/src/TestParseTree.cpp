#include "../includes/ParseTree.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {


	if (argc < 1) {
		return EXIT_FAILURE;
	}

	printf( "\nHello World\n\n" );
	Scanner* s = new Scanner("/home/descb/Documents/sysProg_ParserProblem/Test.txt");

	Token* t;

	ofstream myfile("/home/descb/Documents/sysProg_ParserProblem/out.txt");

//		while ( s->eofChar != (char)'\0'){
//			t = s->getNextToken();
//			cout << "token: "<< t << endl;
//			s->output->writeInFile(t, &myfile);
//
//		}

	myfile.close();
	ParseTree* parseTree = new ParseTree(s);
// hier typecheck von tree machen

	return EXIT_SUCCESS;
}
