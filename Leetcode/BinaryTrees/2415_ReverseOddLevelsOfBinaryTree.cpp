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
	void dfs(TreeNode* left, TreeNode* right, int level) {
		if (!left || !right) return;

		if (level % 2 == 1) {
			int leftVal = left->val;
			int rightVal = right->val;
			left->val = rightVal;
			right->val = leftVal;
		}

		dfs(left->left, right->right, level + 1);
		dfs(left->right, right->left, level + 1);
	}

	TreeNode* reverseOddLevels(TreeNode* root) {
		dfs(root->left, root->right, 1);
		return root;
	}

};
