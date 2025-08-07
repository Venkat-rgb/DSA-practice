/**
 * The function finds the lowest common ancestor of two nodes in a binary search tree.
 * 
 * @param root The `root` parameter is a pointer to the root node of a binary search tree (BST). In a
 * BST, each node has at most two child nodes, referred to as the left child and the right child. The
 * value of the left child is less than the value of the parent node,
 * @param p p is a TreeNode representing one of the nodes in a binary search tree for which we want to
 * find the lowest common ancestor.
 * @param q The `q` parameter in the `lowestCommonAncestor` function represents one of the nodes whose
 * lowest common ancestor we are trying to find in a binary search tree.
 * 
 * @return a pointer to the lowest common ancestor of nodes `p` and `q` in the binary search tree
 * rooted at `root`.
 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL) return root;

    TreeNode *curr = root;

    while(true) {
        if(curr -> val > p -> val && curr -> val > q -> val) {
            curr = curr -> left;
        } 
        else if(curr -> val < p -> val && curr -> val < q -> val) {
            curr = curr -> right;
        }
        else return curr;
    }

    return root;
}