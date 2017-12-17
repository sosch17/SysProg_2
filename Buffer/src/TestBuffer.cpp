#include "../includes/Buffer.h"
#include "../Buffer.cpp"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv) {

	char* input = "/home/stud/lkt/fbi/hele1015/Downloads/sysProg/SimpleTest.txt";


	Buffer*  buffer = new Buffer(1024,input);

	char a = buffer->getNextChar();
	cout << a << endl;

//std::cout <<"fdf" << std::endl; // Ausgabe
//	ofstream myfile("out.txt");
//	while ( a != (char)'\0'){
//			a = buffer->getNextChar();
//			myfile << a << endl;
//			cout <<a << endl;
////			printf("%c",a);
////			//printf("%d",buffer->offset);
//	}
//	std::cout <<"\n" << std::endl;
//
//	for (int i=0; i<150; i++){
//			char a = buffer->getPreviousChar();
//			printf("%c",a);
//			//printf("%d",buffer->offset);
//	}
//
//	std::cout <<"\n" << std::endl;
//
//char current = buffer->getLastListedChar();
//printf("%c",current);
//
//
//	cout << buffer->getNextChar() << endl;
//	cout << buffer->getNextChar() << endl;
//	cout << buffer->getNextChar() << endl;
//	cout << buffer->getLastListedChar() << endl;


//	myfile.close();

	return 0;
}
