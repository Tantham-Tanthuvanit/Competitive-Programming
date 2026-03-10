#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	int getDecimalValue(ListNode* head) {
		std::vector<int> values;
		
		ListNode* ptr = head;

		while (ptr != nullptr) {
		
			for (auto& i : values) {
				i *= 2;
			}

			values.push_back(ptr->val);
			ptr = ptr->next;
		
		}

		int total = 0;

		for (auto& i : values) {
			total += i;
		}

		return total;

	}
};

