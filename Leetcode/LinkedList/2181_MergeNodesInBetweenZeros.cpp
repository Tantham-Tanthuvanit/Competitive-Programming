#include <iostream>

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
  ListNode *mergeNodes(ListNode *head) {
		ListNode* traverse_node = head;
		ListNode* last_zero = head;
		int sum = 0;

		while (traverse_node->next != nullptr) {

			traverse_node = traverse_node->next;

			if (traverse_node->val != 0) {
				sum += traverse_node->val;
			} else {
				last_zero->val = sum;

				if (traverse_node->next == nullptr) {
					last_zero->next = nullptr;
					break;
				}

				last_zero->next = traverse_node;

				last_zero = traverse_node;
				sum = 0;
			}
		}

		delete traverse_node;

		return head;
	}
};
