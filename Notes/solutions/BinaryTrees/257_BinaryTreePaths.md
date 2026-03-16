# 257 BINARY TREE PATHS
- [LEETCODE LINK]("https://leetcode.com/problems/binary-tree-paths/description/?envType=problem-list-v2&envId=backtracking")
- ==DIFFICULTY      :   EASY==
- ==DATE COMPLETED  :   3/13/2026 @ 2:18AM==
---

## PERSONAL NOTES
Found it kind of hard to imagine how the pathing would work, but it has taught me 
to trust reccursion to do most of the heavy lifting for now

---
## TASK STATEMENT
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

Example 1:

Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:

Input: root = [1]
Output: ["1"]

Constraints:
- Number of nodes in the tree is [1, 100]
- -100 <= Node.val <= 100

> [!NOTE] TLDR
> return all paths in the tree as a vector of strings
---
## SOLUTION

### INTUITION
create a function that recursively traverses through the binary tree
**CASES**:
- BASECASE: if node is nullptr then backtrack
- MAIN CASE: add current node into path
- PUSH CASE: if node is a leef then push current path into vector of paths
- LAST CASE: recursively check the nodes left and right paths

### CODE IMPLEMENTATION
```cpp
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
```

#### EXPLANATION
1. store all the paths inside of the vector paths
```cpp
vector<string> paths;
```

2. create helper function using dfs
```cpp
void dfs(TreeNode* root, string path) {}
```
    - root is the current node we are interested in
    - path is the current path string we are on

3. add current value to path
```cpp
path += to_string(root->val)
```

4. check if current node is a leaf
```cpp
if (!root->left && !root->right) {
    paths.push_back(path);
    return;
}
```
    - add current path tot he list of paths
    - backtrack

5. reccursively go call this function to solve for left and right nodes
```cpp
dfs(root->left, path);
dfs(root->right, path);
```
