#include "Stack.h"

Stack::Stack() {
	top = nullptr;
}

Stack::~Stack() {
	clear();
}

bool Stack::is_empty() {
	return top == nullptr;
}

void Stack::push(int value) {
	Node* tmp = new Node();
	tmp->value = value;
	tmp->prev = top;
	top = tmp;
}


int Stack::pop() {
	if (!is_empty()) {
		int tmp_val = top->value;
		Node* tmp_top = top;
		top = top->prev;
		delete tmp_top;
		return tmp_val;
	}
	return -322;
}

void Stack::clear() {
	while (!is_empty()) {
		pop();
	}
}

int Stack::peek() {
	if (!is_empty()) {
		return top->value;
	}
}

Stack::iterater Stack::getTop() {
	return top;
}

Stack::iterater Stack::getNext(iterater a) {
	if (a != nullptr) {
		return a->prev;
	}
}

int Stack::getValue(iterater a) {
	if (a == nullptr)
		return -322;
	else
		return a->value;
}