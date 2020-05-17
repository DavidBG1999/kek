//Bagdasaryn M-35
#pragma once

class Queue
{
private:
	struct Node {
		int value;
		Node* next;
		Node() {
			next = nullptr;
		}
	};
	Node* front;
	Node* back;

public:
	Queue();
	~Queue();
	
	typedef Node* iterater;
	iterater getFront();
	iterater getBack();
	iterater getNext(iterater a);
	int getValue(iterater a);
	void push(int);
	int pop();
	bool is_empty();
	void clear();
	int peekFront();

	int peekBack();

};
