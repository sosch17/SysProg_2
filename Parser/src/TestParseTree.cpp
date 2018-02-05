#include "../includes/TypeCheck.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {


	if (argc < 1) {
		return EXIT_FAILURE;
	}

	Scanner* s = new Scanner("/home/stud/lkt/fbi/brjo1022/workspace/SysProg_2-master/Test.txt");

	Token* t;

	ofstream myfile("/home/stud/lkt/fbi/brjo1022/workspace/SysProg_2-master/out.txt");

//		while ( s->eofChar != (char)'\0'){
//			t = s->getNextToken();
//			cout << "token: "<< t << endl;
//			s->output->writeInFile(t, &myfile);
//
//		}

	myfile.close();
	ParseTree* parseTree = new ParseTree(s);
	TypeCheck* typeCheck = new TypeCheck(parseTree);
// hier typecheck von tree machen

	return EXIT_SUCCESS;
}
