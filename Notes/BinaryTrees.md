# BINARY TREES

- Binary trees is just a tree that is made out of smaller trees
- When solving, use reccursion and trust recursion to figure out the answer, dont everthink

## Basic structure for LEETCODE style problems

```cpp
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
```

---
## Cool trick for solving all binary tree problems

- when solving a tree related problem always ask what should my function
  return for each nodes subtree
- Think as if every function call is answering one question about it's subtree
- Trust and use recursion to solve the smaller subtrees

- Almost every tree will follow a certain pattern:
    1. Base case 
    ```cpp 
        // base case pattern
        if (!root) return something;
        // for example
        if (!root) return 0;
    ```
    2. Solve subtrees [ main code chunk ]
    ```cpp
        // basic patern
        int left = solve(root->left);
        int right = solve(root->right);
    ```
    3. do something with current node
    ```cpp
        // basic pattern
        int current = something_with(root->val);
        // example
        int currentVal = (root->val >= low && root->val <= high) ? root->val : 0;
    ```
    4. combine results
    ```cpp
        // basic pattern
        return currentVal + leftSum + rightSum;
    ```
