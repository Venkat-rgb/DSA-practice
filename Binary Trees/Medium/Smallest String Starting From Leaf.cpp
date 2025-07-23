/**
 * The function `smallestFromLeaf` finds the smallest string formed by concatenating the values of
 * nodes on the path from the root to a leaf node in a binary tree.
 * 
 * @param root The `root` parameter is a pointer to the root of a binary tree node.
 * @param currStr `currStr` is a string that is used to store the current path from the root to a leaf
 * node in the binary tree. It is updated as the helper function traverses the tree from the root to
 * the leaf nodes.
 * @param smallStr The `smallStr` parameter is a reference to a string that stores the smallest string
 * formed by traversing from a leaf node to the root node in a binary tree. The function
 * `smallestFromLeaf` aims to find the smallest string formed by traversing from a leaf node to the
 * root node
 * 
 * @return The function `smallestFromLeaf` is returning the smallest string formed by traversing from a
 * leaf node to the root in a binary tree.
 */
void helper(TreeNode *root, string &currStr, string &smallStr) {
    if(root == NULL) return;

    currStr += (char)('a' + root -> val);

    if(root -> left == NULL && root -> right == NULL) {
        reverse(currStr.begin(), currStr.end());
        if(smallStr.empty() || smallStr > currStr) {
            smallStr = currStr;
        }
        reverse(currStr.begin(), currStr.end());
    }
    
    helper(root -> left, currStr, smallStr);
    helper(root -> right, currStr, smallStr);

    currStr.pop_back();
}

string smallestFromLeaf(TreeNode* root) {
    string temp = "", smallStr = "";

    if(root == NULL) return temp;

    helper(root, temp, smallStr);

    return smallStr;
}