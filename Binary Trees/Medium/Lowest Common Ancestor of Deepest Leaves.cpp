/**
 * The function `lcaDeepestLeaves` finds the lowest common ancestor of the deepest leaves in a binary
 * tree.
 * 
 * @param root The given code snippet is for finding the Lowest Common Ancestor (LCA) of the deepest
 * leaves in a binary tree. The function `lcaHelper` recursively finds the deepest leaves in the binary
 * tree and returns a pair containing the deepest leaf node and its depth.
 * 
 * @return The function `lcaDeepestLeaves` returns the lowest common ancestor (LCA) of the deepest
 * leaves in the binary tree rooted at `root`.
 */
pair <TreeNode*, int> lcaHelper(TreeNode *root) {
    if(root == NULL) return {NULL, 0};

    if(root -> left == NULL && root -> right == NULL) return {root, 1};

    pair <TreeNode*, int> leftRes = lcaHelper(root -> left);
    pair <TreeNode*, int> rightRes = lcaHelper(root -> right);

    if(leftRes.second > rightRes.second) {
        return {leftRes.first, leftRes.second + 1};
    }

    if(rightRes.second > leftRes.second) {
        return {rightRes.first, rightRes.second + 1};
    }

    return {root, max(leftRes.second, rightRes.second) + 1};
}

TreeNode* lcaDeepestLeaves(TreeNode* root) {
    return lcaHelper(root).first;
}