#include "../includes/TypeCheck.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {


	if (argc < 1) {
		return EXIT_FAILURE;
	}

	Scanner* s = new Scanner("/home/leonie/Downloads/SysProg_2/Test.txt");

//	ofstream myfile("/home/leonie/Downloads/SysProg_2/out.txt");

//		while ( s->eofChar != (char)'\0'){
//			t = s->getNextToken();
//			cout << "token: "<< t << endl;
//			s->output->writeInFile(t, &myfile);
//
//		}

//	myfile.close();
	ParseTree* parseTree = new ParseTree(s);
	new TypeCheck(parseTree);
// hier typecheck von tree machen

	return EXIT_SUCCESS;
}
