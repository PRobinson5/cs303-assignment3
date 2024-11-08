#include "queue.h"
#include "function.h"
#include "singleLinkedList.h"
#include <iostream>

using namespace std;

int main() {

	Queue<int> queue = Queue<int>();
	for (int i = 0; i < 10; i++)
		queue.push(i);
	cout << "Before move_to_rear: ";
	queue.display();
	queue.move_to_rear();
	cout << "After move_to_rear: ";
	queue.display();
	cout << endl;
	
	vector<int> numbers = { 0, 1, 3, 0, 4, 4 };
	cout << "Vector: [ ";
	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << " ";
	}
	cout << "]" << endl;

	int key = 0;
	int last_pos = linear_search<int>(numbers, key);
	cout << "Last position of 0: " << last_pos << endl;
	key = 4;
	last_pos = linear_search<int>(numbers, key);
	cout << "Last position of 4: " << last_pos << endl;
	key = 5;
	last_pos = linear_search<int>(numbers, key);
	cout << "Last position of 5: " << last_pos << endl;
	cout << endl;

	SingleLinkedList<int> linkedList = SingleLinkedList<int>();
	for (int i = 9; i > 0; i--)
		linkedList.push_back(i);
	cout << "Before sorting: ";
	linkedList.display();
	linkedList.insertion_sort();
	cout << "After sorting: ";
	linkedList.display();
}