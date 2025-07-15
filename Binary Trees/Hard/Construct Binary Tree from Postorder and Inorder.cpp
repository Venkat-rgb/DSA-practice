/**
 * The `buildTree` function constructs a binary tree from inorder and postorder traversal sequences of
 * the tree.
 * 
 * @param inorder The `inorder` vector represents the inorder traversal of a binary tree, which means
 * the sequence of nodes visited in the following order: left child, root, right child.
 * @param postorder The `postorder` vector represents the postorder traversal of a binary tree. In
 * postorder traversal, the nodes are visited in the order left, right, root.
 * @param mp The `mp` parameter is an unordered map that stores the indices of elements in the
 * `inorder` vector. It maps the element value to its index in the inorder traversal of the binary
 * tree. This map is used to efficiently find the index of the root node in the inorder traversal,
 * which helps
 * @param inStart The `inStart` parameter represents the starting index of the current inorder
 * traversal segment. It indicates the index in the inorder traversal where the current subtree starts.
 * @param inEnd The parameter `inEnd` represents the ending index of the current inorder traversal in
 * the `buildTreeHelper` function. It indicates the index of the last element in the inorder traversal
 * array for the current subtree being processed.
 * @param postStart The `postStart` parameter in the `buildTreeHelper` function represents the starting
 * index of the current subtree in the postorder traversal array. It helps in determining the
 * boundaries of the left and right subtrees for constructing the binary tree recursively.
 * @param postEnd The parameter `postEnd` represents the index of the last element in the postorder
 * traversal array. In the `buildTreeHelper` function, it is used to determine the root node of the
 * current subtree being constructed. It helps in identifying the root value in the postorder traversal
 * array.
 * 
 * @return The `buildTree` function returns the root of a binary tree constructed from the given
 * inorder and postorder traversal sequences of the tree.
 */
TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder,
                              unordered_map<int, int> &mp,
                              int inStart, int inEnd, int postStart,
                              int postEnd) {
    if (inStart > inEnd || postStart > postEnd)
        return NULL;

    int postRoot = postorder[postEnd];
    int inRoot = mp[postorder[postEnd]];
    int leftTreeSize = inRoot - inStart;

    TreeNode* root = new TreeNode(postRoot);

    TreeNode* leftTree =
        buildTreeHelper(inorder, postorder, mp, inStart, inRoot - 1,
                        postStart, postStart + leftTreeSize - 1);
    TreeNode* rightTree =
        buildTreeHelper(inorder, postorder, mp, inRoot + 1, inEnd,
                        postStart + leftTreeSize, postEnd - 1);

    root -> left = leftTree;
    root -> right = rightTree;
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map <int, int> mp;

    for (int i = 0; i < inorder.size(); ++i) {
        mp[inorder[i]] = i;
    }

    return buildTreeHelper(inorder, postorder, mp, 0, inorder.size() - 1, 0,
                            postorder.size() - 1);
}