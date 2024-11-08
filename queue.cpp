#include "queue.h"
#include<iostream>

template <class Item_Type>
Queue<Item_Type>::Queue() {
	head = nullptr;
	tail = nullptr;
	num_items = 0;
}

template <class Item_Type>
void Queue<Item_Type>::push(Item_Type data) {
	Node<Item_Type>* newNode = new Node<Item_Type>(data);
	if (empty()) {
		tail = newNode;
		head = newNode;
	}
	else {
		Node<Item_Type>* newNode = new Node<Item_Type>(data);
		tail->next = newNode;
		tail = newNode;
	}
	num_items++;
}

template <class Item_Type>
Item_Type Queue<Item_Type>::pop() {
	if (head == tail)
		tail = nullptr;
	Node<Item_Type>* delNode = head;
	Item_Type returnData = delNode->data;
	head = head->next;
	delete delNode;
	delNode = nullptr;
	num_items--;
	return returnData;
}

template <class Item_Type>
Item_Type Queue<Item_Type>::front() {
	return head->data;
}

template <class Item_Type>
size_t Queue<Item_Type>::size() {
	return num_items;
}

template <class Item_Type>
bool Queue<Item_Type>::empty() {
	return (head == nullptr);
}

template <class Item_Type>
void Queue<Item_Type>::display() {
	int i = num_items;
	while (i > 0) {
		Item_Type value = this->pop();
		cout << value << " ";
		this->push(value);
		i--;
	}
	cout << endl;
}

template <class Item_Type>
void Queue<Item_Type>::move_to_rear() {
	if (this->empty())
		return;
	Item_Type value = this->pop();
	this->push(value);
}

template class Queue<int>;