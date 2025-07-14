/**
 * The function `buildTree` constructs a binary tree from its preorder and inorder traversal sequences
 * using a helper function `buildTreeHelper`.
 * 
 * @param preorder The `preorder` parameter is a vector of integers representing the preorder traversal
 * of a binary tree. In preorder traversal, the root node is visited first, then the left subtree, and
 * finally the right subtree.
 * @param inorder The `inorder` vector represents the inorder traversal of a binary tree, which means
 * the sequence of nodes visited in the following order: left subtree, root, right subtree.
 * @param mp The `mp` parameter is an unordered map that stores the indices of elements in the
 * `inorder` vector. It maps the elements of the `inorder` vector to their indices in the vector. This
 * mapping is used to efficiently find the index of the root node in the inorder traversal, which
 * @param inStart The `inStart` parameter represents the starting index of the current subtree in the
 * inorder traversal. It helps in determining the boundaries of the left and right subtrees within the
 * inorder traversal array.
 * @param inEnd The parameter `inEnd` represents the ending index of the current inorder traversal in
 * the `buildTreeHelper` function. It indicates the index of the last element in the inorder traversal
 * array for the current subtree being processed.
 * @param preStart The `preStart` parameter in the `buildTreeHelper` function represents the starting
 * index of the current subtree in the preorder traversal array. It indicates the position of the root
 * node of the current subtree in the preorder traversal.
 * @param preEnd The parameter `preEnd` represents the index of the last element in the preorder
 * traversal of the binary tree. In the `buildTreeHelper` function, it is used to determine the range
 * of elements in the preorder traversal that need to be considered for constructing the current
 * subtree.
 * 
 * @return The function `buildTree` returns the root of the binary tree constructed using the preorder
 * and inorder traversal sequences provided as input.
 */
TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder,
                              unordered_map<int, int>& mp, int inStart,
                              int inEnd, int preStart, int preEnd) {

    if (inStart > inEnd || preStart > preEnd)
        return NULL;

    int preRoot = preorder[preStart];
    int inRoot = mp[preorder[preStart]];
    int leftTreeSize = inRoot - inStart;

    TreeNode* root = new TreeNode(preRoot);

    TreeNode* leftTree =
        buildTreeHelper(preorder, inorder, mp, inStart, inRoot - 1,
                        preStart + 1, preStart + leftTreeSize);

    TreeNode* rightTree =
        buildTreeHelper(preorder, inorder, mp, inRoot + 1, inEnd,
                        preStart + leftTreeSize + 1, preEnd);

    root -> left = leftTree;
    root -> right = rightTree;
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> mp;

    for (int i = 0; i < inorder.size(); ++i) {
        mp[inorder[i]] = i;
    }

    return buildTreeHelper(preorder, inorder, mp, 0, inorder.size() - 1, 0,
                            preorder.size() - 1);
}