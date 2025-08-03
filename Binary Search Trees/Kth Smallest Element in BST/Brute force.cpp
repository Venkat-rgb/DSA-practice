/**
 * The function `kthSmallest` finds the kth smallest element in a binary search tree.
 * 
 * @param root The `root` parameter in the `kthSmallestHelper` function represents the root of the
 * binary search tree (BST) from which you want to find the kth smallest element.
 * @param k The parameter `k` in the `kthSmallest` function represents the position of the element you
 * want to find in the binary search tree. It indicates the kth smallest element you are looking for in
 * the tree.
 * @param cnt The `cnt` parameter in the `kthSmallestHelper` function is used to keep track of the
 * number of nodes visited so far while performing an inorder traversal of the binary search tree. It
 * is incremented each time a node is visited, and when `cnt` becomes equal to `k`,
 * @param res The `res` parameter in the `kthSmallestHelper` function is used to store the result of
 * the k-th smallest element found in the binary search tree. It is passed by reference so that the
 * value can be updated within the function and the updated value can be accessed outside the function
 * in
 * 
 * @return The function `kthSmallest` is returning the kth smallest element in a binary search tree
 * represented by the `TreeNode* root`.
 */
void kthSmallestHelper(TreeNode *root, int k, int &cnt, int &res) {
    if(root == NULL) return;

    kthSmallestHelper(root -> left, k, cnt, res);
    cnt++;
    if(cnt == k) {
        res = root -> val;
        return;
    }
    kthSmallestHelper(root -> right, k, cnt, res);
}

int kthSmallest(TreeNode* root, int k) {    
    int cnt = 0, res = -1;
    kthSmallestHelper(root, k, cnt, res);
    return res;
}