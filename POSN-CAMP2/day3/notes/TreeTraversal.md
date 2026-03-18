# TRAVERSAL METHODS FOR BINARY TREES
---
### Preorder Traversal
- First visit its own node
- Then left subtree
- Then right subtree

**EX:**

    [1]
   /   \
 [2]   [3]

> [!NOTE] Preorder Traversal result: [1,2,3]

#### RECURSIVE APROACH
- Print root node
- Traverse left subtree completely
- Traverse right subtree completely
```
void preOrder(Node* node, vector<int>& res) {
    if (node == nullptr) 
        return;
    
    res.push_back(node -> data);

    preOrder(node->left, res);
    preOrder(node->right, res);
}
```
