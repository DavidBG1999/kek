#include "Queue.h"

Queue::Queue() {
	front = nullptr;
	back = nullptr;
}

Queue::~Queue() {
	clear();
}

bool Queue::is_empty() {
	return front == nullptr && back == nullptr;
}

void Queue::push(int value) {
	Node* tmp = new Node();
	tmp->value = value;
	if (is_empty()){
		back = front = tmp;
	}
	else{
		back->next = tmp;
		back = tmp;
	}
}


int Queue::pop() {
	if (!is_empty()) {
		int tmp_val = front->value;
		Node* tmp_front = front;
		if (front->next){
			front = front->next;
		}
		else{
			back = front = nullptr;
		}
		
		delete tmp_front;
		return tmp_val;
	}
	return -322;
}

void Queue::clear() {
	while (!is_empty()) {
		pop();
	}
}

int Queue::peekFront() {
	if (!is_empty()) {
		return front->value;
	}
}

int Queue::peekBack() {
	if (!is_empty()) {
		return back->value;
	}
}

Queue::iterater Queue::getFront() {
	return front;
}

Queue::iterater Queue::getBack() {
	return back;
}

Queue::iterater Queue::getNext(iterater a) {
	if (a != nullptr) {
		return a->next;
	}
}

int Queue::getValue(iterater a) {
	if (a == nullptr)
		return -322;
	else
		return a->value;
}