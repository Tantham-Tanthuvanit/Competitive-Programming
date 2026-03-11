#include <utility>
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

	int result = 0;

	std::pair<int, int> dfs(TreeNode* root) {
		if (!root) return {0,0};

		auto [leftSum, leftCount] = dfs(root->left);
		auto [rightSum, rightCount] = dfs(root->right);

		int sum = root->val + leftSum + rightSum;
		int count = 1 + leftCount + rightCount;

		if (sum / count == root->val)
			result++;

		return {sum, count};
	}

	int averageOfSubtree(TreeNode* root) {
		dfs(root);
		return result;
	}
private:
};
