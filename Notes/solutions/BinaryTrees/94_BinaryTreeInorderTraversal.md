# 401 BINARY WATCH
- [LEETCODE LINK](https://leetcode.com/problems/binary-tree-inorder-traversal)
- ==DIFFICULTY        :   EASY==
- ==DATE COMPLETED  :   3/13/2026 @ 4:31AM==
---
## PERSONAL NOTES
pretty easy once I got the basic concept down

---
## TASK STATEMENT
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:
- Input: root = [1,null,2,3]
- Output: [1,3,2]

Example 2:
- Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
- Output: [4,2,6,5,7,1,3,9,8]

Example 3:
- Input: root = []
- Output: []

Example 4:
- Input: root = [1]
- Output: [1]

Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100
---
## SOLUTION

### INTUITION
Inorder traversal of a subtree is when you visit the left side first and then process the root node and finally process the right side

### CODE IMPLEMENTATION
```cpp
class Solution {
public:
	vector<int> ans;

	void inorder(TreeNode* root) {
		if (root == nullptr) return;

		inorderTraversal(root->left);
		ans.push_back(root->val);
		inorderTraversal(root->right);
	}

	vector<int> inorderTraversal(TreeNode* root)  {
		inorder(root);
		return ans;
	}
};
```
