#pragma once

class Stack
{
private:
	struct Node {
		int value;
		Node* prev;
		Node() {
			prev = nullptr;
		}
	};
	Node* top;
public:
	Stack();
	~Stack();
	
	typedef Node* iterater;
	iterater getTop();
	iterater getNext(iterater a);
	int getValue(iterater a);
	void push(int);
	int pop();
	bool is_empty();
	void clear();
	int peek();
};