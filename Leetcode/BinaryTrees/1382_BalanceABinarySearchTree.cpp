#include <algorithm>
#include <vector>

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
	
	std::vector<int> valuesInNodes;

	void getNodes(TreeNode* root) {
		if (!root) return;
		valuesInNodes.push_back(root->val);
		getNodes(root->left);
		getNodes(root->right);
	}

	TreeNode* constructTree(int l, int r) {
		if (l > r) return nullptr;

		int mid = (l + r) / 2;
		TreeNode* node = new TreeNode(valuesInNodes[mid]);

		node->left = constructTree(l, mid - 1);
		node->right = constructTree(mid + 1, r);

		return node;
	}

	TreeNode* balanceBST(TreeNode* root) {
		getNodes(root);
		std::sort(valuesInNodes.begin(), valuesInNodes.end());

		return constructTree(0, valuesInNodes.size() - 1);
	}
};
