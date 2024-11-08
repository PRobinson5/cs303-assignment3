#include "queue.h"
#include "function.h"
#include <iostream>

using namespace std;

int main() {

	Queue<int> queue = Queue<int>();
	for (int i = 0; i < 10; i++)
		queue.push(i);
	queue.display();

	
}