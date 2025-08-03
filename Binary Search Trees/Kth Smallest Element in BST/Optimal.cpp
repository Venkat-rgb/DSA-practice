/**
 * The function `kthSmallest` finds the kth smallest element in a binary search tree.
 * 
 * @param root The `root` parameter in the function `kthSmallest` is a pointer to the root node of a
 * binary search tree (BST). The function aims to find the kth smallest element in the BST.
 * @param k The parameter `k` in the function `kthSmallest` represents the kth smallest element that we
 * are looking for in the binary search tree represented by the `TreeNode* root`. The function aims to
 * find and return the kth smallest element in the BST.
 * 
 * @return The function `kthSmallest` returns the k-th smallest element in a binary search tree
 * represented by the `TreeNode* root`.
 */
int kthSmallest(TreeNode* root, int k) {
    int cnt = 0, res = -1;

    TreeNode *curr = root;

    while(curr != NULL) {
        if(curr -> left == NULL) {
            cnt++;
            if(cnt == k) {
                res = curr -> val;
            }
            curr = curr -> right;
        }
        else {
            TreeNode *temp = curr -> left;

            while(temp -> right != NULL && temp -> right != curr) {
                temp = temp -> right;
            }

            if(temp -> right == NULL) {
                temp -> right = curr;
                curr = curr -> left;
            }
            else {
                cnt++;
                if(cnt == k) {
                    res = curr -> val;
                }
                temp -> right = NULL;
                curr = curr -> right;
            }
        }
    }

    return res;
}