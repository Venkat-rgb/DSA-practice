/**
 * The function `countNodes` calculates the total number of nodes in a complete binary tree.
 * 
 * @param root The code snippet you provided is for counting the total number of nodes in a complete
 * binary tree. The functions `leftHeight` and `rightHeight` are used to calculate the height of the
 * left and right subtrees respectively, and the `countNodes` function recursively calculates the total
 * number of nodes in
 * 
 * @return The `countNodes` function returns the total number of nodes in a binary tree rooted at the
 * given `root` node.
 */
int leftHeight(TreeNode* root) {
    int depth = 0;
    while (root != NULL) {
        root = root->left;
        depth++;
    }
    return depth;
}

int rightHeight(TreeNode* root) {
    int depth = 0;
    while (root != NULL) {
        root = root->right;
        depth++;
    }
    return depth;
}

int countNodes(TreeNode* root) {
    if(root == NULL) return 0;

    int lh = leftHeight(root);
    int rh = rightHeight(root);

    if(lh == rh) return (1 << lh) - 1;

    int leftRes = countNodes(root -> left);
    int rightRes = countNodes(root -> right);
    
    return 1 + leftRes + rightRes;
}