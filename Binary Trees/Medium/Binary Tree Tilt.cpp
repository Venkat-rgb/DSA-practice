/**
 * The function calculates the tilt of a binary tree and returns the total tilt value.
 * 
 * @param root The code snippet provided is a C++ function that calculates the tilt of a binary tree.
 * The function `helper` recursively calculates the tilt of each node in the binary tree and returns a
 * pair containing the sum of values and the total tilt of the subtree rooted at that node.
 * 
 * @return The function `findTilt` is returning the total tilt of the binary tree rooted at `root`. The
 * `helper` function calculates the tilt of each node and returns a pair containing the sum of values
 * of the subtree rooted at the current node and the total tilt of the subtree rooted at the current
 * node. The `findTilt` function then returns the total tilt of the entire binary tree by
 */
pair <int, int> helper(TreeNode *root) {
    if(root == NULL) return {0, 0};

    pair <int, int> leftAns = helper(root -> left);
    pair <int, int> rightAns = helper(root -> right);

    int currNodeTilt = abs(leftAns.first - rightAns.first);
    int totalTilt = currNodeTilt + leftAns.second + rightAns.second;

    int totalSum = root -> val + leftAns.first + rightAns.first;
    return {totalSum, totalTilt};
}

int findTilt(TreeNode* root) {
    return helper(root).second;
}