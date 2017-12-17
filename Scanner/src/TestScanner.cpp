#include "../includes/Scanner.h"

int main(int argc, char* argv[]){

	if (argc < 1) {
		return EXIT_FAILURE;
	}

	//Scanner* s = new Scanner("/home/stud/lkt/fbi/hele1015/Downloads/sysProg/Test.txt");
	Scanner* s = new Scanner(argv[1]);

	Token* t;

	ofstream myfile("/home/stud/lkt/fbi/brjo1022/workspace/sysProg23_11_17/out.txt");

		while ( s->eofChar != (char)'\0'){
			t = s->getNextToken();
			s->output->writeInFile(t, &myfile);
		}

	myfile.close();

	return EXIT_SUCCESS;
}

