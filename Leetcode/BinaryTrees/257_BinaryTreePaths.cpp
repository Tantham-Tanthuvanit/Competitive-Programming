#include <vector>
#include <string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

	vector<string> paths;

	void dfs(TreeNode* root, string path) {
		if (!root) return;

		path += to_string(root->val);

		if (!root->left && !root->right) {
			paths.push_back(path);
			return;
		}

		path += "->";

		dfs(root->left, path);
		dfs(root->right, path);
	}

	vector<string> binaryTreePaths(TreeNode* root) {
		dfs(root, "");
		return paths;
	}
};
