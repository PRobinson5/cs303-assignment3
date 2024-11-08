#pragma once
#include "queue.h"

using namespace std;

template <class Item_Type>
class SingleLinkedList {
private:
	Node<Item_Type>* head;
	Node<Item_Type>* tail;
	size_t num_items;

public:
	SingleLinkedList();

	void push_front(Item_Type data);
	void push_back(Item_Type data);
	Item_Type pop_front();
	Item_Type pop_back();
	Item_Type front();
	Item_Type back();
	bool empty();
	void insert(size_t index, const Item_Type& item);
	bool remove(size_t index);
	size_t find(const Item_Type& item);
	void insertion_sort();
	void display();

};