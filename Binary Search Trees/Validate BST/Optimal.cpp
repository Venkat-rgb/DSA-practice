/**
 * The function isValidBST checks if a binary search tree is valid by recursively checking the values
 * of each node against a given range.
 * 
 * @param root The `root` parameter is a pointer to the root node of a binary search tree (BST).
 * @param minimum The `minimum` parameter in the `isValidBSTHelper` function represents the minimum
 * value that a node's value can take in the binary search tree (BST) rooted at the current node. This
 * is used to ensure that all nodes in the left subtree of the current node have values less than the
 * current
 * @param maximum The `maximum` parameter in the `isValidBSTHelper` function represents the maximum
 * value that a node's value can take in the subtree rooted at the current node. This is used to ensure
 * that all nodes in the left subtree have values less than the current node's value, and all nodes in
 * the
 * 
 * @return The function `isValidBST` is returning the result of calling the `isValidBSTHelper` function
 * with the root node of the binary search tree, along with the minimum and maximum values that a
 * node's value can take in the tree. The `isValidBSTHelper` function recursively checks if the current
 * node's value is within the valid range defined by the minimum and maximum values, and then
 * recursively checks the
 */
bool isValidBSTHelper(TreeNode *root, long minimum, long maximum) {
    if(root == NULL) return true;

    if(root -> val <= minimum || root -> val >= maximum) {
        return false;
    }

    bool leftRes = isValidBSTHelper(root -> left, minimum, root -> val);
    if(!leftRes) return false;

    bool rightRes = isValidBSTHelper(root -> right, root -> val, maximum);
    if(!rightRes) return false;
    
    return true;
}

bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
}