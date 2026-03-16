#include <algorithm>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:

	int sum = 0;

	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
	}

	void dfs(TreeNode* root, int depth, int maxDepth) {
		if (root == nullptr) return;
		if (root->left == nullptr && root->right == nullptr && depth == maxDepth) sum += root->val;
		else {
			dfs(root->left, depth + 1, maxDepth);
			dfs(root->right, depth + 1, maxDepth);
		}
	}

	int deepestLeavesSum(TreeNode* root) {
		dfs(root, 1, maxDepth(root));
		return sum;
	}
};
