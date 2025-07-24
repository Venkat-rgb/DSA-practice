/**
 * The function `maxPathSum` calculates the maximum sum of a path from the root of a binary tree to a
 * leaf node, considering special cases where the root has only one child.
 * 
 * @param root The `root` parameter in the given code represents the root node of a binary tree. The
 * code is designed to find the maximum path sum in a binary tree where the path can start from any
 * node and end at any node (it does not necessarily have to go through the root).
 * @param maxSum The `maxSum` parameter in the `maxPathSumHelper` function is a reference to an integer
 * that stores the maximum path sum found so far during the traversal of the binary tree. It is updated
 * whenever a new maximum path sum is encountered while traversing the tree. This reference allows the
 * function
 * 
 * @return The function `maxPathSum` returns the maximum sum of a path from any node to any other node
 * in the given binary tree.
 */
int maxPathSumHelper(Node *root, int &maxSum) {
    if(root == NULL) return 0;
    
    if(root -> left == NULL && root -> right == NULL) return root -> data;
    
    int leftPathMaxSum = maxPathSumHelper(root -> left, maxSum);
    int rightPathMaxSum = maxPathSumHelper(root -> right, maxSum);
    
    // If current node is not special node, then calculate global maxSum
    // Bcz, current node has both left and child which can form left-to-leaf path
    if(root -> left != NULL && root -> right != NULL) {
        maxSum = max(maxSum, root -> data + leftPathMaxSum + rightPathMaxSum);
        return root -> data + max(leftPathMaxSum, rightPathMaxSum);
    }
    
    // If current node is special node, then we can't calculate global maxSum
    // Bcz, current node has only single leaf node
    
    return root -> data + (root -> left != NULL ? leftPathMaxSum : rightPathMaxSum);
}

int maxPathSum(Node* root) {
    int maxSum = INT_MIN;
    
    int res = maxPathSumHelper(root, maxSum);
    
    if(root -> left == NULL || root -> right == NULL) {
        maxSum = max(maxSum, res);
    }
    
    return maxSum;
}