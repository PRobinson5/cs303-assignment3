#pragma once
#include <vector>

using namespace std;

template <typename Item_Type>
int linear_search (vector<Item_Type>& items, Item_Type& target, size_t pos = 0, size_t pos_last = -1) {
	if (pos == items.size())
		return pos_last;
	if (target == items[pos])
		pos_last = pos;
	return linear_search(items, target, pos + 1, pos_last);
}