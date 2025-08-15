/**
 * The given C++ functions aim to recover a binary search tree by finding and swapping two misplaced
 * nodes.
 * 
 * @param root The `root` parameter in this context refers to the root node of a binary search tree
 * (BST). The functions `inorder`, `findTwoNodes`, and `recoverTree` are used to recover a binary
 * search tree that has two nodes swapped.
 * @param res The `res` vector in the provided code is used to store the inorder traversal of the
 * binary search tree. It is passed by reference to the `inorder` function to store the elements in
 * sorted order. Later, this sorted vector is used to identify the two nodes that need to be swapped in
 * 
 * @return The functions `inorder`, `findTwoNodes`, and `recoverTree` are not returning any value
 * explicitly. They are all void functions, meaning they do not have a return type specified. These
 * functions are performing operations on the input TreeNode pointers and vectors passed to them, but
 * they do not return any specific value.
 */
void inorder(TreeNode* root, vector<int>& res) {
    if (root == NULL)
        return;

    inorder(root->left, res);
    res.push_back(root -> val);
    inorder(root->right, res);
}

void findTwoNodes(TreeNode* root, int& idx, vector<int>& res) {
    if (root == NULL)
        return;

    findTwoNodes(root->left, idx, res);

    if(root -> val != res[idx]) {
        root -> val = res[idx];
    }
    idx++;

    findTwoNodes(root->right, idx, res);
}

void recoverTree(TreeNode* root) {
    if (root == NULL)
        return;

    vector<int> res;
    inorder(root, res);
    sort(res.begin(), res.end());

    int idx = 0;
    findTwoNodes(root, idx, res);
}