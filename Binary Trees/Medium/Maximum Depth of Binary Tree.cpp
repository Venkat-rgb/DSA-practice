/**
 * The function calculates the maximum depth of a binary tree starting from the root node.
 * 
 * @param root The `root` parameter is a pointer to the root node of a binary tree. The function
 * `maxDepth` calculates the maximum depth of the binary tree starting from the root node.
 * 
 * @return The function `maxDepth` is returning the maximum depth of the binary tree rooted at the
 * given `root` node.
 */
int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int leftTreeHeight = maxDepth(root -> left);
        int rightTreeHeight = maxDepth(root -> right);

        return 1 + max(leftTreeHeight, rightTreeHeight);
    }