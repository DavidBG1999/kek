//Bagdasaryn M-35

#pragma once

class DoublyLinkedList {
private:
	struct Node {
		int value;
		Node* next;
		Node* prev;
		Node() {
			next = prev = nullptr;
		}
	};
	Node* head;
	Node* tail;

public:
	DoublyLinkedList();
	~DoublyLinkedList();

	typedef Node* Iterator;
	Iterator getHead();
	Iterator getTail();
	Iterator getNext(Iterator a);
	Iterator getPrev(Iterator a);
	int getValue(Iterator a);
	void pushAfter(int value, int pos);
	void pushAfter(int value, Iterator iter);
	void pushToHead(int value);
	void pushToTail(int value);
	int popHead();
	int popTail();
	int popFromPos(int pos);
	int popFromPos(Iterator iter);
	bool is_empty();
	void clear();
	void sort();
};