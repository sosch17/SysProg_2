/*
 * LinkedList.h
 *
 *  Created on: Okt 26, 2016
 *      Author: hele1015
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>

template <class T>

class Node {
public:
	/*
	 *  Konstruktor
	 *  Param: T* myData (generische Daten)
	 */

	Node(T* myData) {
		this->data = myData;
		this->next = NULL;
	}
	virtual ~Node() {
		delete [] this->data;
		delete [] this->next;
	}

	/*
	 * Gibt Adresse auf nächsten Knoten zurück.
	 * Return: Node* next
	 */
	Node* getNext() {
		return this->next;
	}

	/*
	 * Setzt neuen Knoten als nächsten Knoten in die LinkedList.
	 * Param: Node* newNode
	 */
	void setNext(Node* newNode) {
		this-> next = newNode;
	}

	/*
	 * Gibt Daten vom Konten zurück.
	 * Return: T* data
	 */
	T* getData() {
		return this->data;
	}


private:
	T* data;
	Node* next;
	};

template <class T>

class LinkedList {
public:
	/*
	 * Konstruktor
	 */
	LinkedList() {
		this->head = new Node<T>(NULL);
	}

	virtual ~LinkedList() {
		delete [] this->head;
	}

	/*
	 * Initialisiere den ersten Knoten mit übergebenenem Inhalt.
	 * Param: T* value
	 */
	void initNode(T* value) {
		this->head = new Node<T>(value);
	}

	/*
	 * Knoten hinzufügen mit übergebenem Inhalt.
	 * Param: T* value
	 */
	void addNode(T* value) {
		Node<T> *newNode = new Node<T>(value);

		Node<T> *cur = head;
		//ab head alle knoten durchgehen bis man am ende ist
		while(cur) {
			if(cur->getNext() == NULL) {
				cur->setNext(newNode);
				return;
			}
			cur = cur->getNext();
		}
	}

	/*
	 * Gibt zurück ob die LinkedList leer ist.
	 * Return: boolean istLeer
	 */
	bool isEmpty() {
		if(head->getData() == NULL) {
			return true;
		}
		return false;
	}

	/*
	 * Gibt erstes Element der LinkedList zurück.
	 * Return: Node<T>* head
	 */
	Node<T>* getHead() {
		return this->head;
	}

private:
	Node<T>* head;
};

#endif /* LINKEDLIST_H_ */


/*
//vergleicht zweit char* aus der Tabelle
int LinkedList::compareNodeData(char* one, char* two) {
	char* ptr = one;
	char* ptr2 = two;
	while (*ptr == *ptr2) {
		ptr++;
		ptr2++;
		if(*ptr == '\0' && *ptr2 == '\0') {
			return 1;
		}
	}
	return 0;
}

// gibt Nodeadresse zurück falls das Wort bereits existiert oder nullptr falls nicht.
Node* LinkedList::lookupNode(struct Node *head, char* lexem) {
	Node* pos = head;
	if(head == nullptr) {
		return nullptr;
	} else {
		while(pos != nullptr) {
			if(compareNodeData(lexem, pos->data) == 1 ) {
				return pos;
			} else {
				pos = pos->next;
			}
	}
		return nullptr;
	}

	return nullptr;
}
*/
