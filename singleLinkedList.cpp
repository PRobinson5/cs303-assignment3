#include "singleLinkedList.h"
#include <iostream>

template <class Item_Type>
SingleLinkedList<Item_Type>::SingleLinkedList() {
	head = nullptr;
	tail = nullptr;
	num_items = 0;
}

template <class Item_Type>
void SingleLinkedList<Item_Type>::push_front(Item_Type data) {
	Node<Item_Type>* newNode = new Node<Item_Type>(data, head);
	head = newNode;
	if (tail == nullptr)
		tail = newNode;
	num_items++;
}

template <class Item_Type>
void SingleLinkedList<Item_Type>::push_back(Item_Type data) {
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
Item_Type SingleLinkedList<Item_Type>::pop_front() {
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
Item_Type SingleLinkedList<Item_Type>::pop_back() {
	Item_Type returnData;
	if (head == tail) {
		returnData = head->data;
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node<Item_Type>* forePtr = head;
		while (forePtr->next->next != nullptr)
			forePtr = forePtr->next;
		returnData = tail->data;
		delete tail;
		tail = forePtr;
		tail->next = nullptr;
		forePtr = nullptr;
	}
	num_items--;
	return returnData;
}

template <class Item_Type>
Item_Type SingleLinkedList<Item_Type>::front() {
	return head->data;
}

template <class Item_Type>
Item_Type SingleLinkedList<Item_Type>::back() {
	return tail->data;
}

template <class Item_Type>
bool SingleLinkedList<Item_Type>::empty() {
	return (head == nullptr);
}

template <class Item_Type>
void SingleLinkedList<Item_Type>::insert(size_t index, const Item_Type& item) {
	if (empty() || index == 0) {
		push_front(item);
		return;
	}
	Node<Item_Type>* foreNode = head;
	int i = 0;
	while (i != (index - 1) && foreNode->next != nullptr) {
		i++;
		foreNode = foreNode->next;
	}
	Node<Item_Type>* newNode = new Node<Item_Type>(item, foreNode->next);
	foreNode->next = newNode;
	tail = newNode;
	foreNode = nullptr;
	num_items++;
}

template <class Item_Type>
bool SingleLinkedList<Item_Type>::remove(size_t index) {
	if (empty())
		return false;
	Node<Item_Type>* foreNode = head;
	int i = 0;
	while (i != (index - 1) && foreNode->next != nullptr) {
		i++;
		foreNode = foreNode->next;
	}
	if (i != (index - 1) && i != 0)
		return false;
	else if (i == 0) {
		pop_front();
		return true;
	}
	else {
		Node<Item_Type>* delNode = foreNode->next;
		foreNode->next = foreNode->next->next;
		delete delNode;
		delNode = nullptr;
	}
	foreNode = nullptr;
	num_items--;
	return true;
}

template <class Item_Type>
size_t SingleLinkedList<Item_Type>::find(const Item_Type& item) {
	size_t index = 0;
	if (empty())
		return index;
	Node<Item_Type>* finder = head;
	while (finder->data != item && finder->next != nullptr) {
		index++;
		finder = finder->next;
	}
	if (finder->data != item)
		return (index + 1);
	return (index);
}

void SingleLinkedList<int>::insertion_sort() {
	Node<int>* key_pos = head->next;
	Node<int>* pos = nullptr;
	int i, j, key;
	
	bool insertionNeeded = false;

	for (j = 1; j < num_items; j++) {
		pos = head;
		key = key_pos->data;
		insertionNeeded = false;
		for (i = 0; i < j; i++) {
			if (key < pos->data) {
				insertionNeeded = true;
				break;
			}
			pos = pos->next;
		}
		if (insertionNeeded) {
			this->insert(i, key);
			key_pos = key_pos->next;
			this->remove(j + 1);
		}
		else
			key_pos = key_pos->next;
	}
}

template <class Item_Type>
void SingleLinkedList<Item_Type>::display() {
	int i = num_items;
	while (i > 0) {
		Item_Type value = this->pop_front();
		cout << value << " ";
		this->push_back(value);
		i--;
	}
	cout << endl;
}

template class SingleLinkedList<int>;