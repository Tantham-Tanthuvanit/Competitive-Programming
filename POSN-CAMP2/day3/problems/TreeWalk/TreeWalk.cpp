#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
	int id;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : id(0), left(nullptr), right(nullptr) {}
	TreeNode(int id) : id(id), left(nullptr), right(nullptr) {}
	TreeNode(int id, TreeNode* left, TreeNode* right) : id(0), left(left), right(right) {}
};

void preOrder(TreeNode* root) {
	if (!root) return;

	cout << root->id << ' ';

	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(TreeNode* root) {
	if (!root) return;

	inOrder(root->left);

	cout << root->id << ' ';

	inOrder(root->right);
}

void postOrder(TreeNode* root) {
	if (!root) return;

	postOrder(root->left);

	postOrder(root->right);

	cout << root->id << ' ';

}

int main() {

	int n; cin >> n;

	unordered_map<int, TreeNode*> nodes;
	unordered_map<int, bool> isChild;

	while (n--) {
		int id, left, right;
		cin >> id >> left >> right;

		// create node if doesnt exist
		if (!nodes[id]) nodes[id] = new TreeNode(id);
		if (left != -1 && !nodes[left]) nodes[left] = new TreeNode(left);
		if (right != -1 && !nodes[right]) nodes[right] = new TreeNode(right);

		// connect children
		if (left != -1) {
			nodes[id]->left = nodes[left];
			isChild[left] = true;
		}

		// connect children
		if (right != -1) {
			nodes[id]->right = nodes[right];
			isChild[right] = true;
		}
	}

	TreeNode* head = nullptr;

	for (auto& [id, node] : nodes) {
		if (!isChild[id]) {
			head = node;
			break;
		}
	}


	cout << "Preorder" << endl;
	preOrder(head);
	cout << "\nInorder" << endl;
	inOrder(head);
	cout << "\nPostorder" << endl;
	postOrder(head);

	return 0;

}
