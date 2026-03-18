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

void insert(TreeNode*& root, int toInsert) {

	if (!root) {
		root = new TreeNode(toInsert);
		return;
	}

	if (root->val > toInsert) {
		if (root->left != nullptr)
			insert(root->left, toInsert);
		else
			root->left = new TreeNode(toInsert);
	}

	else if (root->val < toInsert) {
		if (root->right != nullptr)
			insert(root->right, toInsert);
		else
			root->right = new TreeNode(toInsert);
	}
}

void inorder(TreeNode* root) {
	if (!root) return;
	inorder(root->left);
	cout << root->val << ' ';
	inorder(root->right);
}

void preorder(TreeNode* root) {
	if (!root) return;
	cout << root->val << ' ';
	preorder(root->left);
	preorder(root->right);
}

bool find(TreeNode* root, int target) {

	if (!root) return false;

	if (root->val == target) return true;
	if (target < root->val)
		return find(root->left, target);
	else
		return find(root->right, target);
}

TreeNode* findMin(TreeNode* root) {
	while (root->left)
		root = root->left;
	return root;
}

TreeNode* remove(TreeNode* root, int val) {
	if (!root) return nullptr;

	if (val < root->val) 
		root->left = remove(root->left, val);
	else if (val > root->val)
		root->right = remove(root->right, val);
	else {
		// node found

		// no child
		if (!root->left && !root->right) {
			delete root;
			return nullptr;
		}

		// 1 child
		if (!root->left) {
			TreeNode* temp = root->right;
			delete root;
			return temp;
		}

		if (!root->right) {
			TreeNode* temp = root->left;
			delete root;
			return temp;
		}

		// 2 children
		TreeNode* successor = findMin(root->right);
		root->val = successor->val;
		root->right = remove(root->right, successor->val);

	}

	return root;
}

int main() {

	TreeNode* root = nullptr;

	int n; cin >> n;
	while (n--) {
		string cmd; cin >> cmd;

		if (cmd == "insert") {
			int val; cin >> val;
			insert(root, val);
			continue;
		}

		if (cmd == "find") {
			int val; cin >> val;
			cout << (find(root, val) ? "yes\n" : "no\n");
			continue;
		}

		if (cmd == "print") {
			inorder(root);
			cout << '\n';
			preorder(root);
			cout << '\n';
			continue;
		}

		if (cmd == "delete") {
			int val; cin >> val;
			root = remove(root, val);
			continue;
		}
	}

	return 0;
}
