/**
 * The function finds the lowest common ancestor of two nodes in a binary search tree.
 * 
 * @param root The `root` parameter is a pointer to the root of a binary search tree (BST).
 * @param p p is a TreeNode representing one of the nodes in a binary search tree for which we want to
 * find the lowest common ancestor.
 * @param q q is a TreeNode pointer representing one of the nodes in a binary search tree for which we
 * want to find the lowest common ancestor.
 * 
 * @return The function `lowestCommonAncestor` is returning a pointer to the lowest common ancestor of
 * nodes `p` and `q` in the binary search tree rooted at `root`.
 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root == p || root == q) return root;

    if(root -> val > p -> val && root -> val > q -> val) {
        return lowestCommonAncestor(root -> left, p, q);
    }
    else if(root -> val < p -> val && root -> val < q -> val) {
        return lowestCommonAncestor(root -> right, p, q);
    }

    return root;
}