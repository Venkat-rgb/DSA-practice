/**
 * The function `maxPathSum` calculates the maximum path sum in a binary tree.
 * 
 * @param root The `root` parameter in the `maxPathSumHelper` function represents the current node
 * being processed in the binary tree. It is of type `TreeNode*`, which is a structure used to
 * represent nodes in a binary tree. Each node typically contains a value, a pointer to the left child
 * node
 * @param maxSum The `maxSum` parameter in the `maxPathSumHelper` function is a reference to an integer
 * that stores the maximum path sum found so far during the traversal of the binary tree. It is updated
 * as the function recursively explores the tree nodes to find the maximum path sum. The final result
 * is
 * 
 * @return The function `maxPathSum` is returning the maximum path sum in a binary tree.
 */
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