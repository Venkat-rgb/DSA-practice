/**
 * The function `rightSideView` returns the right side view of a binary tree by performing a
 * depth-first search traversal.
 * 
 * @param root The `root` parameter is a pointer to the root node of a binary tree.
 * @param level The `level` parameter in the `dfs` function represents the current level or depth of
 * the `TreeNode` in the binary tree. It is used to keep track of the level of the node being processed
 * during the depth-first search traversal.
 * @param res `res` is a reference to a vector of integers that will store the values of the nodes seen
 * from the right side in a binary tree. The `rightSideView` function aims to populate this vector with
 * the rightmost values at each level of the binary tree.
 * 
 * @return The function `rightSideView` is returning a vector of integers, which represents the right
 * side view of a binary tree.
 */
void dfs(TreeNode *root, int level, vector <int> &res) {
        if(root == NULL) return;

        if(level == res.size()) {
            res.push_back(root -> val);
        }

        dfs(root -> right, level + 1, res);
        dfs(root -> left, level + 1, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector <int> res;
        dfs(root, 0, res);
        return res;
    }