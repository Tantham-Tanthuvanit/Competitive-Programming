#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int rangeSumBST(TreeNode* root, int low, int high) {
		if (root == nullptr) return 0;

		// check if root is in these cases, if so then add its value to the sum if not then set sum to 0
		int currentVal = (root->val >= low && root->val <= high) ? root->val : 0;

		// calculate the sum of the left subtree
		if (root->val < low)
			return rangeSumBST(root->right, low, high);

		// calculate the sum of the right subtree
		if (root->val > high)
			return rangeSumBST(root->left, low, high);

		return currentVal + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
	}
};

