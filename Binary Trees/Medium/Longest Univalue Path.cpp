/**
 * The function `longestUnivaluePath` calculates the length of the longest path in a binary tree where
 * all nodes have the same value.
 * 
 * @param root The `root` parameter in the `longestUnivaluePathHelper` function represents the root of
 * a binary tree node. The function is designed to find the length of the longest path in the tree
 * where all nodes have the same value.
 * @param maxLen The `maxLen` parameter is a reference to an integer that is used to keep track of the
 * length of the longest univalue path found so far in the binary tree traversal. It is passed by
 * reference to the `longestUnivaluePathHelper` function so that its value can be
 * 
 * @return The function `longestUnivaluePath` returns the length of the longest path in the binary tree
 * where all nodes have the same value.
 */
int longestUnivaluePathHelper(TreeNode *root, int &maxLen) {
    if(root == NULL) return 0;

    int leftLongPathLen = longestUnivaluePathHelper(root -> left, maxLen);
    int rightLongPathLen = longestUnivaluePathHelper(root -> right, maxLen);

    if(root -> left != NULL && root -> val == root -> left -> val) {
        leftLongPathLen += 1;
    }
    else {
        leftLongPathLen = 0;
    }
    
    if(root -> right != NULL && root -> val == root -> right -> val) {
        rightLongPathLen += 1;
    }
    else {
        rightLongPathLen = 0;
    }

    maxLen = max(maxLen, leftLongPathLen + rightLongPathLen);

    return max(leftLongPathLen, rightLongPathLen);
}

int longestUnivaluePath(TreeNode* root) {
    int maxLen = 0;

    longestUnivaluePathHelper(root, maxLen);

    return maxLen;
}