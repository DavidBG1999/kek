//Bagdasaryn M-35

#pragma once

#include "DoublyLinkedList.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

void menu() {
	int index = 322;
	DoublyLinkedList my_list;
	while (index != 0) {
		cout << "Enter 1 to push to first" << endl;
		cout << "Enter 2 tp push to last" << endl;
		cout << "Enter 3 to push after position" << endl;
		cout << "Enter 4 to fill the list randomly" << endl;
		cout << "Enter 5 to pop from position" << endl;
		cout << "Enter 6 to clear the list" << endl;
		cout << "Enter 7 to display the whole list" << endl;
		cout << "Enter 8 to sort list" << endl;
		cout << "Enter 9 save in file" << endl;
		cout << "Enter 10 load from file" << endl;
		cout << "Enter 11 for test 1" << endl;
		cout << "Enter 12 for test 2" << endl;
		cout << "Enter 13 for test 3" << endl;
		cout << "Enter 14 for test 4" << endl;
		cout << "Enter 0 to exit" << endl;
		cin >> index;
		cout << endl;
		switch (index) {
		case 0:
			return;
		case 1: {
			int n;
			cout << "Enter number of elements:" << endl;
			cin >> n;
			for (int i = 0; i < n; i++) {
				int value;
				cout << "Enter value of element:" << endl;
				cin >> value;
				my_list.pushToHead(value);
			}
			break;
		}
		case 2: {
			int n;
			cout << "Enter number of elements:" << endl;
			cin >> n;
			for (int i = 0; i < n; i++) {
				int value;
				cout << "Enter value of element:" << endl;
				cin >> value;
				my_list.pushToTail(value);
			}
			break;
		}
		case 3: {
			
			int pos;
			cout << "Enter position of element:" << endl;
			cin >> pos;
			int n;
			cout << "Enter number of elements:" << endl;
			cin >> n;
			for (int i = 0; i < n; i++) {
				int value;
				cout << "Enter value of element:" << endl;
				cin >> value;
				my_list.pushAfter(value, pos);
			}
			break;
		}
		case 4: {
			int n;
			srand(time(NULL));
			cout << "Enter number of elements:" << endl;
			cin >> n;
			for (int i = 0; i < n; i++) {
				int value = rand() % 1000;
				my_list.pushToTail(value);
			}
			break;
		}
		case 5: {
			if (!my_list.is_empty()) {
				int pos;
				cout << "Enter position of element:" << endl;
				cin >> pos;
				cout << my_list.popFromPos(pos) << endl;
			}
			else {
				cout << "List is empty!" << endl;
			}
			break;
		}
		case 6: {
			if (!my_list.is_empty()) {
				my_list.clear();
				cout << "Succesfully cleared" << endl;
			}
			else {
				cout << "List is empty!" << endl;
			}
			break;
		}
		case 7: {
			if (!my_list.is_empty()) {
				DoublyLinkedList::Iterator iter;
				iter = my_list.getHead();
				while (iter) {
					cout << my_list.getValue(iter) << endl;
					iter = my_list.getNext(iter);
				}
			}
			else {
				cout << "List is empty!" << endl;
			}
			break;
		}
		case 8: {
			if (!my_list.is_empty()) {
				my_list.sort();
				cout << "List sorted!" << endl;
			}
			else {
				cout << "List is empty!" << endl;
			}
			break;
		}
		case 9: {
			DoublyLinkedList::Iterator iter;
			ofstream out;
			out.open("DoublyLinkedList.txt");
			if (out.is_open()) {
				iter = my_list.getHead();
				while (iter) {
					out << my_list.getValue(iter) << endl;
					iter = my_list.getNext(iter);
				}
				out.close();
				break;
			}
		}
		case 10: {
			string line;
			ifstream in;
			in.open("DoublyLinkedList.txt");
			if (in.is_open()) {
				while (getline(in, line)) {
					my_list.pushToTail(stoi(line));
				}
			}
			in.close();
			break;
		}
		case 11: {
			my_list.clear();
			my_list.pushToHead(228);
			my_list.pushToHead(322);
			if (my_list.popHead() == 322) {
				cout << "Test completed successfully!" << endl;
			}
			else
				cout << "Test failed!" << endl;
			break;
		}
		case 12: {
			my_list.pushToTail(322);
			my_list.clear();
			if (my_list.is_empty()) {
				cout << "Test completed successfully!" << endl;
			}
			else
				cout << "Test failed!" << endl;
			break;
		}
		case 13: {
			my_list.clear();
			my_list.pushToTail(322);
			if (my_list.getHead() == my_list.getTail()) {
				cout << "Test completed successfully!" << endl;
			}
			else
				cout << "Test failed!" << endl;
			break;
		}
		case 14: {
			my_list.clear();
			my_list.pushToHead(322);
			my_list.pushToTail(228);
			if (my_list.getNext(my_list.getHead()) == my_list.getTail()) {
				cout << "Test completed successfully!" << endl;
			}
			else
				cout << "Test failed!" << endl;
			break;
		}
		default:
			cout << "Error" << endl;
			break;
		}
	}
}