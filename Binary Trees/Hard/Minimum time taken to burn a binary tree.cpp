/**
 * The function calculates the amount of time it takes for a signal to reach a specific node in a
 * binary tree.
 * 
 * @param root The `root` parameter in the given code represents the root node of a binary tree. The
 * code is designed to calculate the amount of time it takes for a signal to travel from the starting
 * node (specified by the `start` parameter) to the farthest leaf node in the binary tree.
 * @param start The `start` parameter in the given code represents the value of the node from which you
 * want to calculate the amount of time it takes for a signal to reach the farthest leaf node in the
 * binary tree. The function `amountOfTime` calculates this time based on the distance between the
 * starting node
 * @param minutes The `minutes` parameter in the `amountOfTimeHelper` function is used to keep track of
 * the maximum time taken to reach the target node `start` from the current node. It is passed by
 * reference so that its value can be updated and retained across recursive calls. The function
 * calculates the time
 * 
 * @return The function `amountOfTime` returns the amount of time it takes for a signal to travel from
 * the starting node to the farthest node in a binary tree, excluding the starting node itself.
 */
int amountOfTimeHelper(TreeNode *root, int start, int &minutes) {
    if(root == NULL) return 0;

    int leftHeight = amountOfTimeHelper(root -> left, start, minutes);
    int rightHeight = amountOfTimeHelper(root -> right, start, minutes);

    if(root -> val == start) {
        minutes = max(leftHeight, rightHeight);
        return -1;
    }

    if(leftHeight < 0) {
        minutes = max(minutes, rightHeight + abs(leftHeight));
        return leftHeight - 1;
    } 

    if(rightHeight < 0) {
        minutes = max(minutes, leftHeight + abs(rightHeight));
        return rightHeight - 1;
    }

    return 1 + max(leftHeight, rightHeight);
}

int amountOfTime(TreeNode* root, int start) {
    int minutes = 0;

    amountOfTimeHelper(root, start, minutes);

    return minutes;
}