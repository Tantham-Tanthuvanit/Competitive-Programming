#include <ios>
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
	// helper function
	void bstToGstHelper(TreeNode* root, int& nodeSum) {
		// base case [ no tree ]
		if (!root) 
			return;

		// right side sum
		bstToGstHelper(root->right, nodeSum);
		// add itself to Sum of nodes
		nodeSum += root->val;
		// update the root value
		root->val = nodeSum;
		// do the left side
		bstToGstHelper(root->left, nodeSum);
	}
};
