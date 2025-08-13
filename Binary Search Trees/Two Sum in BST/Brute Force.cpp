/**
 * The function `findTarget` checks if there are two elements in a binary search tree that add up to a
 * given target value `k`.
 * 
 * @param root The `root` parameter in the given code represents the root of a binary search tree
 * (BST). The `TreeNode` structure likely contains a value (`val`), a pointer to the left child node
 * (`left`), and a pointer to the right child node (`right`). The `inorder`
 * @param res The `res` parameter is a reference to a vector of integers. This vector is used to store
 * the values of the binary search tree nodes in sorted order during an inorder traversal.
 * 
 * @return The function `findTarget` returns a boolean value. It returns `true` if there exist two
 * elements in the binary search tree (BST) whose sum is equal to the given target `k`, otherwise it
 * returns `false`.
 */
 void inorder(TreeNode *root, vector <int> &res) {
    if(root == NULL) return;

    inorder(root -> left, res);
    res.push_back(root -> val);
    inorder(root -> right, res);
}

bool findTarget(TreeNode* root, int k) {
    if(root == NULL) return false;
    vector <int> res;
    inorder(root, res);

    int i = 0, j = res.size() - 1;

    while(i < j) {
        int sum = res[i] + res[j];
        if(sum > k) {
            j--;
        }
        else if(sum < k) {
            i++;
        }
        else {
            return true;
        }
    }

    return false;
}