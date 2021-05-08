#pragma once
#include <string>
#include <sstream>
using namespace std;
class Node
{
private:
	Node* next;
	Node* previous;
	string data;
public:
	Node(string newData) {
		data = newData;
		next = nullptr;
		previous = nullptr;
	};
	string getData() { return data; }
	void setData(string newData) { data = newData; }
	Node* getNext() { return next; }
	Node* getPrevious() { return previous; }
	void setNext(Node* newNext) { next = newNext; }
	void setPrevious(Node* newPrevious) { previous = newPrevious; }
	string showNode() {
		stringstream ss;
		ss << this
			<< " Node[Next: " << next
			<< " Previous: " << previous
			<< " Data: " << data
			<< "]";
		return ss.str();
	}
};



