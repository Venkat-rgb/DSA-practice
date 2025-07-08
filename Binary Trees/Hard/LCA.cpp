/**
 * The function finds the lowest common ancestor of two nodes in a binary tree.
 * 
 * @param root The `root` parameter is a pointer to the root of a binary tree.
 * @param p The `p` parameter in the `lowestCommonAncestor` function represents one of the nodes whose
 * lowest common ancestor we are trying to find. This function is typically used in binary trees to
 * find the lowest common ancestor of two given nodes `p` and `q`.
 * @param q The `q` parameter in the `lowestCommonAncestor` function represents one of the nodes for
 * which we want to find the lowest common ancestor in a binary tree. This function is designed to find
 * the lowest common ancestor of two given nodes `p` and `q` in a binary tree with
 * 
 * @return The function `lowestCommonAncestor` returns a pointer to the lowest common ancestor of nodes
 * `p` and `q` in the binary tree with the given `root`.
 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root == p || root == q) return root;

    TreeNode *leftDescendant = lowestCommonAncestor(root -> left, p, q);
    TreeNode *rightDescendant = lowestCommonAncestor(root -> right, p, q);

    if(leftDescendant == NULL) {
        return rightDescendant;
    }

    if(rightDescendant == NULL) {
        return leftDescendant;
    }

    return root;
}