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
	TreeNode* bstToGst(TreeNode* root) {
		int nodeSum = 0;
		bstToGstHelper(root, nodeSum);
		return root;
	}
private:
	// this function traverses the tree starting from the right side
	// then keeps track of all the nodes and their sums using a variable
	void bstToGstHelper(TreeNode* root, int& nodeSum) {
		// if root is null then make no changes
		if (!root)
			return;

		bstToGstHelper(root->right, nodeSum);
		nodeSum += root->val;
		// Update root value 
		root->val = nodeSum;
		bstToGstHelper(root->left, nodeSum);

	}
};
