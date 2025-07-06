/**
 * The function calculates the diameter of a binary tree by recursively finding the height of each node
 * and updating the maximum diameter.
 * 
 * @param root The `root` parameter in the `height` function represents the root of a binary tree. It
 * is a pointer to the TreeNode structure that contains information about a particular node in the
 * tree.
 * @param maxLen `maxLen` is a reference parameter that is used to store the maximum diameter of the
 * binary tree. It is updated within the `height` function as the maximum length of the path between
 * two nodes in the tree.
 * 
 * @return The function `diameterOfBinaryTree` is returning the diameter of the binary tree, which is
 * the maximum distance between any two nodes in the tree.
 */
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