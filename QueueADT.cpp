// QueueADT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//
//

		//		____ _  _ ____ _  _ ____
		//		|  | |  | |___ |  | |___
		//		| _\ |__| |___ |__| |___
		//
//
//	A fun simulation of the Queue datatype, in a bank where you wait for your token.
//	Implemented by Saad Ahmed Bazaz
//	FAST NUCES, Islamabad
//
//

#include <iostream>
#include "Queue.h"
using namespace std;
int main()
{
    std::cout << "Hello World!\n";
	Queue<int> A;
	int option;
	do {
		cout << "Welcome to the Bank! Would you like to collect your waiting token? \nEnter:" << endl;
		cout << "1 to get your token, \n2 to shout and quarrel with the person in the front of the line and make him leave, \n3 to eradicate everyone including yourself, \n0 to exit the bank." << endl;
		cin >> option;

		if (option == 1) {
			int generate;
			cout << endl;
			cout << "Enter a number for token generation." << endl;
			cin >> generate;
			cout << endl;
			A.enqueue(generate);
		}
		else if (option == 2) {
			cout << endl;
			cout << "You: YAAR JALDI KARO KYA KAR RAHE HO BANK AAYE HO YA BEAUTY SALON" << endl;
			cout << endl;
			auto person = A.dequeue();
			if (person) {
				cout << "Token #" << person << " left the game." << endl;
			}
			else {
				cout << "Who else are you to blame except for yourself?" << endl;
			}
			
		}
		else if (option == 3) {
			cout << endl;
			cout << "Omae wa mou shinderu." << endl;
			cout << endl;
			A.clear();
			cout << "They are already dead." << endl;
		}

		cout << endl;
		cout << "------------------------------------------" << endl;
		cout << "is Empty? " << A.isEmpty() << endl;
		A.Display();

		cout << "There are " << A.getLength() << " people in the line." << endl;
		if (A.getLength()) 	cout << "That's it. You can wait." << endl;
		else cout << "Your turn has arrived. Finally!" << endl;

		cout << "------------------------------------------" << endl<<endl;
	} while (option);

}

