#include "../includes/LinkedList.h"
#include <iostream>
using namespace std;


int main(int argc, char **argv) {

	LinkedList<int>* linkedList;
	linkedList = new LinkedList<int>();

	int fuenf = 5;
	int sechs = 6;
	int sieben = 7;
	int acht = 8;

	cout << linkedList->isEmpty() << endl;

	linkedList->initNode(&fuenf);

	linkedList->addNode(&sechs);

	linkedList->addNode(&sieben);

	linkedList->addNode(&acht);

	cout << linkedList->isEmpty() << endl;


}
