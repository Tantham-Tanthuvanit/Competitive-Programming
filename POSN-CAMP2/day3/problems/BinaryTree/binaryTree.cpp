#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
	int id;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int id) : id(id), left(nullptr), right(nullptr) {}
	TreeNode(int id, TreeNode* left, TreeNode* right) : id(id), left(left), right(right){}
};

struct Data {
	int nodeNum;
	int parent;
	int degrees;
	int depth;
	int height;
	int sibling;
	string type;
};

int getDegrees(TreeNode* root) {
	int ans = 0;
	if (root->left != nullptr) ans++;
	if (root->right != nullptr) ans++;

	return ans;
}


void getDepth(TreeNode* root, int depth, unordered_map<int,Data>& depthMap) {
	if (!root) return;

	depthMap[root->id].depth = depth;

	getDepth(root->left, depth + 1, depthMap);
	getDepth(root->right, depth + 1, depthMap);
	
}

void assignTypes(TreeNode* root, unordered_map<int, Data>& dataMap) {
    if (!root) return;

    // determine type for current node
    if (dataMap[root->id].parent == -1) {
        dataMap[root->id].type = "root";
    }
    else if (!root->left && !root->right) {
        dataMap[root->id].type = "leaf";
    }
    else {
        dataMap[root->id].type = "internal node";
    }

    // recurse
    assignTypes(root->left, dataMap);
    assignTypes(root->right, dataMap);
}

void getSiblings(TreeNode* root,
                 unordered_map<int, Data>& dataMap,
                 unordered_map<int, TreeNode*>& nodes) {

    if (!root) return;

    int parent = dataMap[root->id].parent;

    if (parent == -1) {
        dataMap[root->id].sibling = -1;
    } else {
        TreeNode* p = nodes[parent];

        if (!p) {
            dataMap[root->id].sibling = -1;
        } 
        else if (p->left && p->left->id == root->id) {
            // I am left child → sibling is right
            dataMap[root->id].sibling = (p->right ? p->right->id : -1);
        } 
        else if (p->right && p->right->id == root->id) {
            // I am right child → sibling is left
            dataMap[root->id].sibling = (p->left ? p->left->id : -1);
        } 
        else {
            dataMap[root->id].sibling = -1;
        }
    }

    getSiblings(root->left, dataMap, nodes);
    getSiblings(root->right, dataMap, nodes);
}

int getHeightMap(TreeNode* root, unordered_map<int,Data>& dataMap) {
	if (!root) return -1;

	int left = getHeightMap(root->left, dataMap);
	int right = getHeightMap(root->right, dataMap);

	int h = 1 + max(left, right);

	dataMap[root->id].height = h;
	

	return h;
}


int main() {

	int n; cin >> n;

	unordered_map<int, TreeNode*> nodes;
	unordered_map<int, bool> isChild;
	unordered_map<int, Data> dataMap;

	vector<int> ids;

	int count = 0;

	while (n--) {
		int id, left, right;

		cin >> id >> left >> right;

		if (!nodes[id]) nodes[id] = new TreeNode(id);

		if (left != -1 && !nodes[left]) nodes[left] = new TreeNode(left);
		if (right != -1 && !nodes[right]) nodes[right] = new TreeNode(right);


		ids.push_back(id);


		if (left != -1) {
			nodes[id]->left = nodes[left];
			dataMap[left].parent = id;
			isChild[left] = true;
		}

		if (right != -1) {
			nodes[id]->right = nodes[right];
			dataMap[right].parent = id;
			isChild[right] = true;
		}

		dataMap[id].nodeNum = count;

		count++;
	}

	TreeNode* root = nullptr;

	for (auto& [id, node] : nodes) {
		if (isChild[id] == false) {
			root = node;
			break;
		}
	}
	
	dataMap[root->id].parent = -1;


	for (auto& [id, node] : nodes) {
		dataMap[id].degrees = getDegrees(node);
	}

	getDepth(root, 0, dataMap);
	getHeightMap(root, dataMap);
	getSiblings(root, dataMap, nodes);
	assignTypes(root, dataMap);

	sort(ids.begin(), ids.end());

	for (int id : ids) {
    cout << "node " << id
         << ": parent = " << dataMap[id].parent
         << ", sibling = " << dataMap[id].sibling
         << ", degree = " << dataMap[id].degrees
         << ", depth = " << dataMap[id].depth
         << ", height = " << dataMap[id].height
         << ", " << dataMap[id].type
         << "\n";
}

	return 0;

}
