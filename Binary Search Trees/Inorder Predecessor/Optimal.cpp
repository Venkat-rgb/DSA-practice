/**
 * The function preDeccessor finds the predecessor node of a given key in a binary search tree.
 * 
 * @param root The `root` parameter in the `preDeccessor` function represents the root node of a binary
 * search tree (BST) from which we want to find the predecessor node of a given key.
 * @param key The `key` parameter in the `preDeccessor` function represents the value of the node for
 * which we want to find the predecessor node in a binary search tree. The predecessor node is the node
 * with the largest value that is smaller than the given key.
 * 
 * @return The function `preDeccessor` returns a pointer to a `Node` which is the predecessor of the
 * node with the given key in a binary search tree.
 */
Node *preDeccessor(Node *root, int key) {
    Node *node = NULL, *curr = root;

    while(curr != NULL) {
        if(curr -> data < key) {
            node = curr;
            curr = curr -> right;
        }
        else {
            curr = curr -> left;
        }
    }
    
    return node;
}
