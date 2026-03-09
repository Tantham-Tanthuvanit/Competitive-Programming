#include <iostream>
#include <list>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
		ListNode* head = list1;
		ListNode* traverse_node = list1;
		int count = 0;

		while (count < a-1) {
			traverse_node = traverse_node->next;
			count++;
		}

		ListNode* a_start = traverse_node;

		while (count < b+1) {
			traverse_node = traverse_node->next;
			count++;
		}

		ListNode* b_end = traverse_node;

		a_start->next = list2;

		traverse_node = list2;

		while (traverse_node->next != nullptr) {
			traverse_node = traverse_node->next;
		}

		traverse_node->next = b_end;

		return head;
	}
};
