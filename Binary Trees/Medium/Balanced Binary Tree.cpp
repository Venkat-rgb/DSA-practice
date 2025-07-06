/**
 * The function `isBalanced` in C++ checks if a binary tree is balanced by calculating the height of
 * each subtree and comparing their difference.
 * 
 * @param root The `root` parameter in the given code represents the root of a binary tree. The
 * `TreeNode` structure likely contains a value, a pointer to the left child node, and a pointer to the
 * right child node. The `height` function calculates the height of the binary tree rooted at the given
 * 
 * @return The function `isBalanced` is returning a boolean value indicating whether the given binary
 * tree `root` is balanced or not. It does so by calling the `height` function which calculates the
 * height of the tree and checks if the tree is balanced based on the heights of its left and right
 * subtrees. If the tree is balanced, the `height` function returns the height of the tree,
 */
int height(TreeNode *root) {
        if(root == NULL) return 0;

        int leftHeight = height(root -> left);
        if(leftHeight == -1) return -1;

        int rightHeight = height(root -> right);
        if(rightHeight == -1) return -1;

        if(abs(leftHeight - rightHeight) > 1) {
            return -1;
        } 

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }