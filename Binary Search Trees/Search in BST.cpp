/**
 * The function `searchBST` searches for a node with a specific value in a binary search tree and
 * returns the node if found, otherwise returns NULL.
 * 
 * @param root The `root` parameter is a pointer to the root node of a binary search tree (BST) where
 * the search operation will be performed.
 * @param val The `val` parameter in the `searchBST` function represents the value that we are
 * searching for in the binary search tree (BST). The function will traverse the BST starting from the
 * root node and search for a node with the value equal to the `val` parameter. If such a node is
 * 
 * @return The function `searchBST` returns a pointer to the `TreeNode` that contains the value `val`
 * if it is found in the binary search tree rooted at `root`. If the value is not found, it returns a
 * `NULL` pointer.
 */
TreeNode* searchBST(TreeNode* root, int val) {
    if(root == NULL) return root;

    TreeNode *curr = root;

    while(curr != NULL) {
        if(curr -> val == val) return curr;
        curr = curr -> val > val ? curr -> left : curr -> right;
    }

    return NULL;
}