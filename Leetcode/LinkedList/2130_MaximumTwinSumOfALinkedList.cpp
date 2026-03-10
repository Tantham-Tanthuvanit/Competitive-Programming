#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	int pairSum(ListNode* head) {
		
		vector<int> nums;

		while (head != nullptr) {
			nums.push_back(head->val);
			head = head->next;
		}

		int size = nums.size()-1;
		int mx = 0;

		for (int i = 0; i < nums.size()/2; i++) {
			mx = max(nums[i] + nums[size - i], mx);
		}

		return mx;

	}
};
