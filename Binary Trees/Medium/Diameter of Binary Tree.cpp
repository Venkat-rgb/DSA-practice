int height(TreeNode *root, int &maxLen) {
        if(root == NULL) return 0;

        int leftHeight = height(root -> left, maxLen);
        int rightHeight = height(root -> right, maxLen);

        maxLen = max(maxLen, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxLen = 0;

        height(root, maxLen);      

        return maxLen;
    }