#include "../includes/TypeCheck.h"
#include "../includes/MakeCode.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {


	if (argc < 1) {
		return EXIT_FAILURE;
	}
//	"/home/stud/lkt/fbi/hele1015/Desktop/16.3.18_SysProg/SysProg_2/Test.txt"
	Scanner* s = new Scanner(argv[1]);

	ParseTree* parseTree = new ParseTree(s);
	new TypeCheck(parseTree);
	ofstream code("/home/stud/lkt/fbi/hele1015/Desktop/16.3.18_SysProg/SysProg_2/out.txt");

	new MakeCode(parseTree, &code);

	return EXIT_SUCCESS;
}
