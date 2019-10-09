#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Item {
	Item <T>* next;
	T data;
	Item() {
		next = nullptr;
	}

	Item(T Data) : data(Data) {
		next = nullptr;
	}
};

template <typename T>
class Queue {
	Item <T>* top;
	int Qsize;

public:
	Queue() :Qsize(0) {
		top = nullptr;
	}

	bool isEmpty() {
		return top == nullptr;
	}

	Item <T>* getTop() const {
		return top;
	}


	void enqueue(T dataItem) {
		Item<T>* newItem = new Item<T>(dataItem);
		Item<T>* currNode = top;
		Item<T>* prevNode = nullptr;
		while (currNode != nullptr) {
			prevNode = currNode;
			currNode = currNode->next;
		}
		if (prevNode) {
			prevNode->next = newItem;
		}
		else {
			top = newItem;
		}
		Qsize++;
	}



	T dequeue() {
		if (isEmpty()) {
			cout << "EXCEPTION: Cannot dequeue an empty list." << endl;
			return NULL;
		}
		Item<T>* toDelete = top;
		top = top->next;
		T temp = toDelete->data;
		delete toDelete;
		Qsize--;
		return temp;
	}

	void clear() {
		while (top != nullptr) {
			Item<T>* toDelete = top;
			top = top->next;
			delete toDelete;
		}
		cout << "Queue cleared successfully." << endl;
		Qsize = 0;
	}

	int getLength() const {
		return Qsize;
	}


	void Display() {
		cout << "Displaying Queue..." << endl;
		Item <T>* cursor = top;
		while (cursor) {
			cout << cursor->data << ", ";
			cursor = cursor->next;
		}
		cout << endl;

	} 

	Item<T>* operator+=(const Queue<T>& otherQueue) {
			Item<T>* currNode = top;
			Item<T>* prevNode = nullptr;
			while (currNode != nullptr) {
				prevNode = currNode;
				currNode = currNode->next;
			}
			if (prevNode) {
				prevNode->next = otherQueue.getTop();
			}
			else {
				top = otherQueue.getTop();
			}
			Qsize+=otherQueue.getLength();
			return this->getTop();
	}


};