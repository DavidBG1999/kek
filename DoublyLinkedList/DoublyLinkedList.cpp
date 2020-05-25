//Bagdasaryn M-35

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() {
	head = nullptr;
	tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
	clear();
}

bool DoublyLinkedList::is_empty() {
	return head == nullptr;
}

void DoublyLinkedList::pushToTail(int value) {
	Node* tmp = new Node;
	tmp->value = value;
	if (!is_empty()) {
		tail->next = tmp;
		tmp->prev = tail;
		tail = tmp;
	}
	else {
		tail = head = tmp;
	}
}

void DoublyLinkedList::pushToHead(int value) {
	Node* tmp = new Node;
	tmp->value = value;
	if (!is_empty()) {
		head->prev = tmp;
		tmp->next = head;
		head = tmp;
	}
	else {
		tail = head = tmp;
	}
}

void DoublyLinkedList::pushAfter(int value, int pos) {
	Node* tmp = new Node;
	tmp->value = value;
	if (!is_empty()) {
		Iterator iter = getHead();
		for (int i = 0; i < pos - 1 && iter->next; i++) {
			iter = iter->next;
		}
		if (!iter) return;
		else {
			tmp->next = iter->next;
			tmp->prev = iter;
			if (iter != tail) {
				iter->next->prev = tmp;
			}
			iter->next = tmp;
		}
	}
	else {
		head = tail = tmp;
	}
}

void DoublyLinkedList::pushAfter(int value, Iterator iter) {
	Node* tmp = new Node;
	tmp->value = value;
	if (!is_empty()) {
		if (!iter) return;
		else {
			tmp->next = iter->next;
			tmp->prev = iter;
			if (iter != tail) {
				iter->next->prev = tmp;
			}
			iter->next = tmp;
		}
	}
	else {
		head = tail = tmp;
	}
}

int DoublyLinkedList::popHead() {
	if (!is_empty()) {
		Node* tmp = new Node;
		tmp = getHead();
		int value = tmp->value;
		if (head == tail) {
			head = tail = nullptr;
		}
		else {
			head = tmp->next;
			head->prev = nullptr;
		}
		delete tmp;
		return value;
	}
	return -322;
}

int DoublyLinkedList::popTail() {
	if (!is_empty()) {
		Node* tmp = new Node;
		tmp = getTail();
		int value = tmp->value;
		if (head == tail) {
			head = tail = nullptr;
		}
		else {
			tail = tmp->prev;
			tail->next = nullptr;
		}
		delete tmp;
		return value;
	}
	return -322;
}

int DoublyLinkedList::popFromPos(int pos) {
	if (!is_empty()) {
		Iterator iter = getHead();
		for (int i = 0; i < pos && iter; i++) {
			iter = getNext(iter);
		}
		int value = iter->value;
		if (iter == head && iter == tail) {
			head = tail = nullptr;
			delete iter;
		}
		else if (iter == head) {
			value = popHead();
		}
		else if (iter == tail) {
			value = popTail();
		}
		else {
			iter->prev->next = iter->next;
			iter->next->prev = iter->prev;
			delete iter;
		}
		return value;
	}
	return -322;
}

int DoublyLinkedList::popFromPos(Iterator iter) {
	if (!is_empty()) {
		Iterator tmp(iter);
		int value = tmp->value;
		if (tmp == head && tmp == tail) {
			head = tail = nullptr;
			delete tmp;
		}
		else if (tmp == head) {
			value = popHead();
		}
		else if (tmp == tail) {
			value = popTail();
		}
		else {
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			delete tmp;
		}
		return value;
	}
	return -322;
}

void DoublyLinkedList::clear() {
	while (!is_empty()) {
		popHead();
	}
}

DoublyLinkedList::Iterator DoublyLinkedList::getHead() {
	if (!is_empty()) {
		return head;
	}
}

DoublyLinkedList::Iterator DoublyLinkedList::getTail() {
	if (!is_empty()) {
		return tail;
	}
}

DoublyLinkedList::Iterator DoublyLinkedList::getNext(Iterator a) {
	if (!is_empty()) {
		return a->next;
	}
}

DoublyLinkedList::Iterator DoublyLinkedList::getPrev(Iterator a) {
	if (!is_empty()) {
		return a->prev;
	}
}

int DoublyLinkedList::getValue(Iterator a) {
	if (!is_empty()) {
		return a->value;
	}
	return -322;
}

void DoublyLinkedList::sort() {
	if (!is_empty() && (head != tail)) {
		Iterator iter = head;
		while (iter->next) {
			Iterator currentElem = iter;
			if (currentElem->value > currentElem->next->value) {
				int value = popFromPos(currentElem->next);
				while ((currentElem->value > value) && currentElem->prev) {
					currentElem = currentElem->prev;
				}
				if (currentElem == head) {
					pushToHead(value);
				}
				else {
					pushAfter(value, currentElem);
				}
			}
			else {
				iter = iter->next;
			}
		}
	}
}