#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    TreeNode() : left(nullptr), right(nullptr) {}
};

TreeNode* build(string& s, int& i) {
    if (s[i] == ',') return nullptr;

    if (s[i] == '(') {
        i++;

        TreeNode* root = new TreeNode();

        if (s[i] != ',') {
            root->left = build(s, i);
        }

        if (s[i] == ',') i++;

        if (s[i] != ')') {
            root->right = build(s, i);
        }

        i++;
        return root;
    }

    return nullptr;
}

TreeNode* intersection(TreeNode* a, TreeNode* b) {
    if (!a || !b) return nullptr;

    TreeNode* root = new TreeNode();
    root->left = intersection(a->left, b->left);
    root->right = intersection(a->right, b->right);

    return root;
}

TreeNode* unioning(TreeNode* a, TreeNode* b) {
    if (!a && !b) return nullptr;

    TreeNode* root = new TreeNode();

    root->left = unioning(a ? a->left : nullptr,
                          b ? b->left : nullptr);

    root->right = unioning(a ? a->right : nullptr,
                           b ? b->right : nullptr);

    return root;
}

void printTree(TreeNode* root) {
    if (!root) {
        cout << "()";
        return;
    }

    cout << "(";

    if (root->left) printTree(root->left);

    cout << ",";

    if (root->right) printTree(root->right);

    cout << ")";
}

int main() {
    char cmd;
    string t1, t2;

    while (cin >> cmd >> t1 >> t2) {
        int i1 = 0, i2 = 0;

        TreeNode* a = build(t1, i1);
        TreeNode* b = build(t2, i2);

        TreeNode* result;

        if (cmd == 'i') {
            result = intersection(a, b);
        } else { // 'u'
            result = unioning(a, b);
        }

        printTree(result);
        cout << '\n';
    }

    return 0;
}
