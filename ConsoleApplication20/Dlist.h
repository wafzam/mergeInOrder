#pragma once
#include "Node.h";
#include <iostream>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
class DList
{
public:
	Node* first;
	Node* last;
	int counter;
	DList() {
		first = nullptr;
		last = nullptr;
		counter = 0;
	};
	void addFromDisk(string fileName) {

		ifstream infile(fileName);
		string newData;

		while (getline(infile, newData)) {
			Node* n1 = new Node(newData);
			addAfter(last, n1);
		}

		infile.close();
	}
	void mergeInOrder(DList* lst2)
	{
		Node* x = lst2->first;
		//int num = 1;
		

		while (x != NULL) {
			string kData = x->getData();
			if (this->findNode(kData) == NULL) {
				Node* tNext = new Node(kData);
				addAfter(last, tNext);
			}
			x = x->getNext();
		}
		Node* q = first;
		
		string temp = "";
		for (Node* q = first; q != NULL; q = q->getNext())
		{
			//k = first;
			for (Node* k=first; k != NULL; k = k->getNext())
			{
				if (q->getData() < k->getData())
				{
					
					temp = k->getData();
					k->setData(q->getData());
					q->setData(temp);
				}
			}
		}

		
	}
	// -------------------------------------------------
	void deleteNode(Node* n) {
		if (n == nullptr) return;
		if (counter == 0) return;
		//CASE1. Only one element in the list?
		if (counter == 1) {
			first = nullptr;
			last = nullptr;
			counter = 0;
			return;
		}
		//Reduce counter
		counter--;
		//CASE2. Deleting the head of the list? //CORRECTS CODE FROM LAB07
		if (n == first) {
			first = first->getNext();
			first->setPrevious(nullptr);
			delete n;
			return;
		}
		// Get references to sourrounding Nodes
		Node* leftNode = n->getPrevious();
		Node* rightNode = n->getNext();
		//CASE3. Deleting last of the list?
		if (n == last) {
			leftNode->setNext(nullptr);
			last = leftNode;
			delete n;
			return;
		}
		//CASE4. interconnect surrounding nodes
		leftNode->setNext(rightNode);
		rightNode->setPrevious(leftNode);
		delete n;
		return;
	}
	// --------------------------------------------
	Node* findNode(string keyData)
	{
		//code was modified to correct earlier error
		Node* p = first;
		while (p != nullptr) {
			string spy = p->getData();
			if (p->getData() == keyData)
				return p;
			else
				p = p->getNext();
		}
		return p;
	}
	void addFirst(Node* n1) {
		//this if-stm was added to correct code from LAB07 ////////////
		if (first == nullptr) {
			first = n1;
			last = n1;
			counter = 1;
			return;
		}
		n1->setNext(first);
		first->setPrevious(n1);
		first = n1;
		counter++;
	}
	void addAfter(Node* n1, Node* n2) {
		// insert new node n2 as a successor of n1
		// we assume Node n2 has data and its next & previous are nullptr.
		//CASE-0. n1 is the nullptr and the list is not empty
		if (n1 == nullptr && counter > 0)
		{
			//add n2 as the first node
			n2->setNext(first);
			first = n2;
			counter++;
			return;
		}
		//CASE-1. The list is empty
		if (counter == 0) {
			first = n2;
			last = n2;
			counter = 1;
			return;
		}
		// add new node
		counter++;
		// find the successor of n1
		Node* n1Successor = n1->getNext();
		if (n1Successor != nullptr)
			n1Successor->setPrevious(n2);
		n1->setNext(n2);
		//collocate n2 in between n1 and n1Successor
		n2->setNext(n1Successor);
		n2->setPrevious(n1);
		//is n2 the last node?
		if (n2->getNext() == nullptr) {
			last = n2;
		}
	}
	void showList() {
		int n = 1;
		cout << endl
			<< " First:" << first
			<< " Last:" << last
			<< " Counter:" << counter << endl;
		Node* p = this->first;
		while (p != nullptr) {
			cout << setw(3) << n++ << " "
				<< p->showNode() << endl;
			p = p->getNext();
		}
	}
	void showListBackward() {
		cout << endl;
		Node* p = this->last;
		while (p != nullptr) {
			cout << p->showNode() << endl;
			p = p->getPrevious();
		}
	}
};

