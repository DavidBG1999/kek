#pragma once
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

void menu() {
	int index = 322;
	Stack my_stack;
	while (index != 0) {
		cout << "Enter 1 to push" << endl;
		cout << "Enter 2 to fill the stack  randomly" << endl;
		cout << "Enter 3 to pop" << endl;
		cout << "Enter 4 to peek" << endl;
		cout << "Enter 5 to clear the stack" << endl;
		cout << "Enter 6 to display the whole stack" << endl;
		cout << "Enter 7 save in file" << endl;
		cout << "Enter 8 load from file" << endl;
		cout << "Enter 9 for test 1" << endl;
		cout << "Enter 10 for test 2" << endl;
		cout << "Enter 11 for test 3" << endl;
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
				my_stack.push(value);
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
				my_stack.push(value);
			}
			break;
		case 3:
			if (!my_stack.is_empty()) {
				cout << my_stack.pop() << endl;
			}
			else
				cout << "Stack is empty!" << endl;
			break;
		case 4:
			if (!my_stack.is_empty()) {
				cout << my_stack.peek() << endl;
			}
			else
				cout << "Stack is empty!" << endl;
			break;
		case 5:
			if (!my_stack.is_empty()) {
				my_stack.clear();
				cout << "Succesfully cleared" << endl;
			}
			else
				cout << "Stack is empty!" << endl;
			break;
		case 6:
			if (!my_stack.is_empty()) {
				Stack::iterater iter;
				iter = my_stack.getTop();
				while (iter) {
					cout << my_stack.getValue(iter) << endl;
					iter = my_stack.getNext(iter);
				}
			}
			else
				cout << "Stack is empty!" << endl;
			break;
		case 7: {
			Stack::iterater iter;
			ofstream out;
			out.open("stack.txt");
			if (out.is_open()) {
				iter = my_stack.getTop();
				while (iter) {
					out << my_stack.getValue(iter) << endl;
					iter = my_stack.getNext(iter);
				}
				out.close();
				break;
			}
		}
		case 8: {
			string line;
			ifstream in;
			in.open("stack.txt");
			if (in.is_open()) {
				while (getline(in, line)) {
					my_stack.push(stoi(line));
				}
			}
			in.close();
			break;
		}
		case 9: {
			my_stack.push(1);
			my_stack.push(2);
			my_stack.push(3);
			Stack::iterater iter;
			iter = my_stack.getTop();
			int test[] = { 3,2,1 };
			bool testCheck = true;
			for (int i = 0; i < 3; i++) {
				int testStack = my_stack.getValue(iter);
				testCheck = (test[i] == testStack);
				if (!testCheck) {
					cout << "Test failed!" << endl;
					break;
				}
				iter = my_stack.getNext(iter);
			}
			if (testCheck)
				cout << "Test completed successfully!" << endl;
			break;
		}
		case 10: {
			my_stack.push(322);
			my_stack.push(228);
			my_stack.pop();
			if (my_stack.pop() == 322) {
				cout << "Test completed successfully!" << endl;
			}
			else
				cout << "Test failed!" << endl;
			break;
		}
		case 11: {
			my_stack.push(322);
			my_stack.clear();
			if (my_stack.is_empty()) {
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