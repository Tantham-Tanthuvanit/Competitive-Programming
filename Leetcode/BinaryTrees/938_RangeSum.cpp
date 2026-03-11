#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* right;
	TreeNode* left;
	TreeNode() : val(0), right(nullptr), left(nullptr) {}
	TreeNode(int x) : val(x), right(nullptr), left(nullptr) {}
	TreeNode(int x, TreeNode* right, TreeNode* left) : val(x), right(right), left(left) {}
};

class Solution {
public:
	int rangeSumBST(TreeNode* root, int low, int high) {
		if (root == nullptr) return 0;

		int currentVal = (root->val >= low && root->val <= high) ? root->val : 0;
		
		if (root->val < low)
			return rangeSumBST(root->right, low, high);

		if (root->val > high)
			return rangeSumBST(root->left, low, high);

		return currentVal + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
	}
};
