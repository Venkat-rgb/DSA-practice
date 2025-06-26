int maxPathSumHelper(TreeNode *root, int &maxSum) {
        if(root == NULL) return 0;

        int leftPathMaxSum = max(0, maxPathSumHelper(root -> left, maxSum));
        int rightPathMaxSum = max(0, maxPathSumHelper(root -> right, maxSum));

        maxSum = max(maxSum, root -> val + leftPathMaxSum + rightPathMaxSum);

        return root -> val + max(leftPathMaxSum, rightPathMaxSum);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;

        maxPathSumHelper(root, maxSum);

        return maxSum;
    }