# 104 MAXIMUM DEPTH
- [LEETCODE LINK](https://leetcode.com/problems/maximum-depth-of-binary-tree)
- ==DIFFICULTY        :   EASY==
- ==DATE COMPLETED  :   3/13/2026 @ 6:00AM==
---
## PERSONAL NOTES
Easy asf

---
## TASK STATEMENT
Find the maximum depth of a given binary tree

---
## SOLUTION

### INTUITION
recursively call a function that add 1 to depth every time we go deeper and then comapir the maxes

### CODE IMPLEMENTATION
```cpp
class Solution {
public:

	int dfs(TreeNode* root, int depth) {
		if (!root) return depth;
	
		return max(dfs(root->left, depth+1), dfs(root->right, depth+1));
	}

	int maxDepth(TreeNode* root) {
		return dfs(root, 0);
	}
};
```
