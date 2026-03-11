#include <iostream>

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
	int averageOfSubtree(TreeNode* root) {
		if (root == nullptr) return 0;
		if (root->right == nullptr && root->left == nullptr) return 1;

		if (getTotal(root) / getCount(root) == root->val) {
			return averageOfSubtree(root->left) + averageOfSubtree(root->right) + 1;
		} else {
			return averageOfSubtree(root->left) + averageOfSubtree(root->right);
		}
	}
private:
	int getTotal(TreeNode* root) {
		if (root == nullptr) return 0;
		return root->val + getTotal(root->left) + getTotal(root->right);
	}

	int getCount(TreeNode* root) {
		if (root == nullptr) return 0;
		return 1 + getCount(root->left) + getCount(root->right);
	}


};
