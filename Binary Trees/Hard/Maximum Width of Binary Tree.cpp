/**
 * The function calculates the maximum width of a binary tree.
 * 
 * @param root The `root` parameter is a pointer to the root of a binary tree.
 * @param level The `level` parameter in the `helper` function represents the level of the current node
 * in the binary tree. It starts at 0 for the root node and increments as we traverse down the tree.
 * This parameter helps us keep track of the level of each node and update the corresponding
 * information in the
 * @param idx The `idx` parameter in the `helper` function represents the index of the current node in
 * the binary tree traversal. It is used to keep track of the position of each node relative to its
 * parent node. The `idx` value is calculated based on the index of the parent node and whether the
 * @param maxWidth The `maxWidth` parameter in the `helper` function is used to keep track of the
 * maximum width of the binary tree encountered so far. It is updated whenever a wider width is found
 * during the traversal of the tree. The final value of `maxWidth` is returned by the `widthOf
 * @param res The `res` parameter in the `widthOfBinaryTree` function is a vector of pairs of long
 * integers. Each pair represents a level in the binary tree, where the first element of the pair is
 * the starting index of the nodes at that level and the second element is the ending index of the
 * 
 * @return The function `widthOfBinaryTree` returns the maximum width of a binary tree.
 */
void helper(TreeNode *root, int level, long idx, long &maxWidth, vector <pair<long, long>> &res) {
    if(root == NULL) return;

    if(level == res.size()) {
        res.push_back({idx, idx});
    }
    else {
        res[level].second = idx;
    }

    maxWidth = max(maxWidth, idx - res[level].first + 1);

    helper(root -> left, level + 1, 2 * (idx - res[level].first), maxWidth, res);
    helper(root -> right, level + 1, 2 * (idx - res[level].first) + 1, maxWidth, res);
}

int widthOfBinaryTree(TreeNode* root) {
    vector <pair <long, long>> res;

    long maxWidth = 0;
    helper(root, 0, 1, maxWidth, res);

    return maxWidth;
}