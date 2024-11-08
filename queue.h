#pragma once

using namespace std;

template <class Item_Type>
struct Node {
	Node* next;
	Item_Type data;
	Node(const Item_Type& data_item, Node* next_ptr = nullptr) {
		next = next_ptr;
		data = data_item;
	}
};

template <class Item_Type>
class Queue {
private:
	Node<Item_Type>* head;
	Node<Item_Type>* tail;
	size_t num_items;

public:
	Queue();

	void push(Item_Type data);
	Item_Type pop();
	Item_Type front();
	size_t size();
	bool empty();
	void display();
	void move_to_rear();

};