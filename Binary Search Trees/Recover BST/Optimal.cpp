/**
 * The `recoverTree` function in C++ identifies and corrects two violations in a binary search tree by
 * swapping the values of the nodes causing the violations.
 * 
 * @param root The `root` parameter is a pointer to the current node being processed in the binary
 * search tree traversal.
 * @param prev The `prev` parameter in the `inorder` function is used to keep track of the previously
 * visited node during the inorder traversal of the binary search tree. It helps in comparing the
 * values of nodes to identify violations in the BST structure.
 * @param first The `first` parameter in the `inorder` function is used to store the first node where a
 * violation of the binary search tree property is found. This violation occurs when the value of a
 * node is less than the value of its previous node during an inorder traversal. The `first` node will
 * @param middle The `middle` parameter in the `inorder` function is used to store the node that is
 * violating the BST property in case of the first violation. It represents the middle node in the
 * sequence of nodes that are out of order.
 * @param last The `last` parameter in the `inorder` function is used to keep track of the last node in
 * the inorder traversal where a violation is detected. This node represents the second violation in
 * the binary search tree (BST) where the values are not in the correct order.
 * 
 * @return The code provided is for recovering a binary search tree with two nodes swapped. The
 * `recoverTree` function takes a binary search tree `root` as input and calls the `inorder` function
 * to identify the two nodes that are swapped. The `inorder` function performs an inorder traversal of
 * the tree and identifies the first and last nodes that violate the BST property.
 */
void inorder(TreeNode *root, TreeNode *&prev, TreeNode *&first, TreeNode *&middle, TreeNode *&last) {
    if(root == NULL) return;

    inorder(root -> left, prev, first, middle, last);
    if(prev == NULL) {
        prev = root;
    }
    else {
        if(prev -> val > root -> val) {
            // Checking for first violation
            if(first == NULL && middle == NULL) {
                first = prev;
                middle = root;
            }
            else {
                // Checking for second violation
                last = root;
            }
        }
        prev = root;
    }
    inorder(root -> right, prev, first, middle, last);
}

void recoverTree(TreeNode* root) {
    if(root == NULL) return;

    TreeNode *prev = NULL, *first = NULL, *middle = NULL, *last = NULL;
    inorder(root, prev, first, middle, last);

    // If it's first violation
    if(first != NULL && last != NULL) {
        swap(first -> val, last -> val);
    }
    else {
        // It's second violation
        swap(first -> val, middle -> val);
    }
}