/**
 * The function `bstFromPreorder` constructs a binary search tree from a given preorder traversal of
 * the tree.
 * 
 * @param preorder A vector of integers representing the preorder traversal of a binary search tree.
 * @param start The `start` parameter in the `constructBST` function is used to keep track of the
 * current index in the `preorder` vector while constructing the binary search tree. It is passed by
 * reference so that its value can be updated across recursive calls. This allows us to traverse the
 * preorder list and
 * @param bound The `bound` parameter in the `constructBST` function represents the maximum value that
 * a node in the Binary Search Tree (BST) can have. This is used to determine whether a node should be
 * placed in the left subtree or the right subtree based on its value relative to the `bound`.
 * 
 * @return The function `bstFromPreorder` is returning the root of a binary search tree constructed
 * from the given preorder traversal of the tree.
 */
TreeNode* constructBST(vector <int> &preorder, int &start, int bound) {
    if(start == preorder.size() || preorder[start] > bound) return NULL;

    TreeNode *root = new TreeNode(preorder[start++]);
    root -> left = constructBST(preorder, start, root -> val);
    root -> right = constructBST(preorder, start, bound);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int start = 0;
    return constructBST(preorder, start, INT_MAX);
}