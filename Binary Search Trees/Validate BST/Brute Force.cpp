/**
 * The function isValidBST checks if a binary search tree is valid by performing an in-order traversal
 * and checking if the resulting values are in ascending order.
 * 
 * @param root The `root` parameter in the `sortedBST` function represents the root node of a binary
 * search tree (BST). The function performs an in-order traversal of the BST to populate the `res`
 * vector with the values of the nodes in sorted order.
 * @param res The `res` parameter is a reference to a vector of integers. This vector is used to store
 * the values of the binary search tree (BST) nodes in sorted order. The `sortedBST` function performs
 * an in-order traversal of the BST and populates this vector with the values of the nodes
 * 
 * @return The function `isValidBST` is returning a boolean value - `true` if the binary search tree
 * (BST) represented by the input `root` is valid, and `false` otherwise.
 */
void sortedBST(TreeNode *root, vector <int> &res) {
    if(root == NULL) return;

    sortedBST(root -> left, res);
    res.push_back(root -> val);
    sortedBST(root -> right, res);
}

bool isValidBST(TreeNode* root) {
    vector <int> res;

    sortedBST(root, res);

    for(int i = 1; i < res.size(); ++i) {
        if(res[i] <= res[i - 1]) return false;
    }

    return true;
}