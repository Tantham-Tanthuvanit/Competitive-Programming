# 100 SAME TREE
- [LEETCODE LINK](https://leetcode.com/problems/same-tree)
- ==DIFFICULTY        :   EASY==
- ==DATE COMPLETED  :   3/13/2026 @ 5:00AM==
---
## PERSONAL NOTES
tried doing it with in order traversal the first time but didnt realise it failed in some test cases. Fixed it now so I should be good

---
## TASK STATEMENT
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:

Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:

Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:

Input: p = [1,2,1], q = [1,1,2]
Output: false

 

Constraints:

    The number of nodes in both trees is in the range [0, 100].
    -104 <= Node.val <= 104
---
## SOLUTION

### INTUITION
repeadedly call the same function over and over again, check if everything is the same, if so move on

### CODE IMPLEMENTATION
```cpp
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p && !q) return true;
		if (!p || !q) return false;
		if (p->val != q->val) return false;

		return isSameTree(p->left, q->left) &&
			   isSameTree(p->right, q->right);
	}

};
```
#### EXPLANATION

1. check if theyre both nullptrs
```cpp
if (!p && !q) return true;
```

2. check if either of them is a nullptr, if so it means the tree is not the same
```cpp
if (!p || !q) return false;
```

3. Check if their values are the same
```cpp
if (p->val != q->val) return false;
```

4. Call the same function for left and right nodes
```cpp
return isSameTree(p->left, q->left) &&
       isSameTree(p->right, q->right);
```
