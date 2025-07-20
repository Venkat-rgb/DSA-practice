void helper(TreeNode *root, int res, int &totalSum) {
    if(root == NULL) return;

    res = (res * 2) + root -> val;

    if(root -> left == NULL && root -> right == NULL) {
        totalSum += res;
        return;
    }

    helper(root -> left, res, totalSum);
    helper(root -> right, res, totalSum);
}

int sumRootToLeaf(TreeNode* root) {
    int totalSum = 0;
    helper(root, 0, totalSum);
    return totalSum;
}