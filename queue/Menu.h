//magdasaryn M-35

#pragma once
#include "Queue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

void menu() {
	int index = 322;
	Queue my_queue;
	while (index != 0) {
		cout << "Enter 1 to push" << endl;
		cout << "Enter 2 to fill the queue randomly" << endl;
		cout << "Enter 3 to pop" << endl;
		cout << "Enter 4 to peek front element" << endl;
		cout << "Enter 5 to peek back element" << endl;
		cout << "Enter 6 to clear the queue" << endl;
		cout << "Enter 7 to display the whole queue" << endl;
		cout << "Enter 8 save in file" << endl;
		cout << "Enter 9 load from file" << endl;
		cout << "Enter 10 for test 1" << endl;
		cout << "Enter 11 for test 2" << endl;
		cout << "Enter 12 for test 3" << endl;
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
				my_queue.push(value);
			}
			break;
		}
		case 2:
			int n;
			srand(time(NULL));
			cout << "Enter number of elements:" << endl;
			cin >> n;
			for (int i = 0; i < n; i++) {
				int value = rand() % 1000;
				my_queue.push(value);
			}
			break;
		case 3:
			if (!my_queue.is_empty()) {
				cout << my_queue.pop() << endl;
			}
			else
				cout << "Queue is empty!" << endl;
			break;
		case 4:
			if (!my_queue.is_empty()) {
				cout << my_queue.peekFront() << endl;
			}
			else
				cout << "Queue is empty!" << endl;
			break;
		case 5:
			if (!my_queue.is_empty()) {
				cout << my_queue.peekBack() << endl;
			}
			else
				cout << "Queue is empty!" << endl;
			break;
		case 6:
			if (!my_queue.is_empty()) {
				my_queue.clear();
				cout << "Succesfully cleared" << endl;
			}
			else
				cout << "Queue is empty!" << endl;
			break;
		case 7:
			if (!my_queue.is_empty()) {
				Queue::iterater iter;
				iter = my_queue.getFront();
				while (iter) {
					cout << my_queue.getValue(iter) << endl;
					iter = my_queue.getNext(iter);
				}
			}
			else
				cout << "Queue is empty!" << endl;
			break;
		case 8: {
			Queue::iterater iter;
			ofstream out;
			out.open("queue.txt");
			if (out.is_open()) {
				iter = my_queue.getFront();
				while (iter) {
					out << my_queue.getValue(iter) << endl;
					iter = my_queue.getNext(iter);
				}
				out.close();
				break;
			}
		}
		case 9: {
			string line;
			ifstream in;
			in.open("queue.txt");
			if (in.is_open()) {
				while (getline(in, line)) {
					my_queue.push(stoi(line));
				}
			}
			in.close();
			break;
		}
		case 10: {
			my_queue.clear();
			my_queue.push(1);
			my_queue.push(2);
			my_queue.push(3);
			Queue::iterater iter;
			iter = my_queue.getFront();
			int test[] = { 1,2,3 };
			bool testCheck = true;
			for (int i = 0; i < 3; i++) {
				int testStack = my_queue.getValue(iter);
				testCheck = (test[i] == testStack);
				if (!testCheck) {
					cout << "Test failed!" << endl;
					break;
				}
				iter = my_queue.getNext(iter);
			}
			if (testCheck)
				cout << "Test completed successfully!" << endl;
			break;
		}
		case 11: {
			my_queue.clear();
			my_queue.push(322);
			my_queue.push(228);
			my_queue.pop();
			if (my_queue.pop() == 322) {
				cout << "Test completed successfully!" << endl;
			}
			else
				cout << "Test failed!" << endl;
			break;
		}
		case 12: {
			my_queue.push(322);
			my_queue.clear();
			if (my_queue.is_empty()) {
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
