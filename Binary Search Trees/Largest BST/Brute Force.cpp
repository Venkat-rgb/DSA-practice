/**
 * The given code is used to find the size of the largest Binary Search Tree (BST) in a given binary
 * tree.
 * 
 * @param root The `root` parameter in the given code represents the root node of a binary tree. The
 * functions `checkBST` and `largestBSTHelper` are used to determine the size of the largest Binary
 * Search Tree (BST) within the binary tree rooted at the given `root` node.
 * @param minimum The `minimum` parameter in the `checkBST` function represents the minimum value that
 * a node's data can take in the binary search tree (BST) rooted at the current node. This value is
 * used to ensure that the left subtree of the current node satisfies the BST property, where all nodes
 * in
 * @param maximum The `maximum` parameter in the `checkBST` function represents the maximum value that
 * a node's data can take in the subtree rooted at the current node. This is used to ensure that the
 * current node's data is less than the `maximum` value to maintain the binary search tree property.
 * 
 * @return The function `largestBst` returns the size of the largest Binary Search Tree (BST) within
 * the given binary tree `root`.
 */
pair <bool, int> checkBST(Node *root, int minimum, int maximum) {
    if(root == NULL) return {true, 0};
    
    if(root -> left == NULL && root -> right == NULL) {
        if(root -> data <= minimum || root -> data >= maximum) return {false, 1};
        return {true, 1}; 
    }
    
    pair <bool, int> leftRes = checkBST(root -> left, minimum, root -> data);
    if(!leftRes.first) return leftRes;
    
    pair <bool, int> rightRes = checkBST(root -> right, root -> data, maximum);
    if(!rightRes.first) return rightRes;
    
    int totalCnt = 1 + leftRes.second + rightRes.second;
    bool isBST = leftRes.first && rightRes.first && root -> data > minimum && root -> data < maximum;
    
    return {isBST, totalCnt};
}

void largestBSTHelper(Node *root, int &maxCnt) {
    if(root == NULL) return;
    
    pair <bool, int> bstRes = checkBST(root, INT_MIN, INT_MAX);
    if(bstRes.first) {
        maxCnt = max(maxCnt, bstRes.second);
    }
    
    largestBSTHelper(root -> left, maxCnt);
    largestBSTHelper(root -> right, maxCnt);
}

int largestBst(Node *root) {
    int maxCnt = 0;
    largestBSTHelper(root, maxCnt);
    return maxCnt;
}