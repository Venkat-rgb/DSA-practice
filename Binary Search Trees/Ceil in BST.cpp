/**
 * The function finds the smallest value in a binary search tree that is greater than or equal to a
 * given input value.
 * 
 * @param root The `root` parameter is a pointer to the root node of a binary search tree (BST). The
 * function `findCeil` is used to find the smallest key in the BST that is greater than or equal to the
 * given `input` value. The function traverses the BST starting from the
 * @param input The function `findCeil` takes a binary search tree node `root` and an integer `input`
 * as parameters. It searches for the smallest value in the tree that is greater than or equal to the
 * `input` value. If the exact value is found in the tree, it returns that
 * 
 * @return The function `findCeil` returns the smallest value in the binary search tree that is greater
 * than or equal to the input value. If the input value is found in the tree, it will return the input
 * value itself. If there is no value greater than or equal to the input value in the tree, it will
 * return -1.
 */
int findCeil(Node* root, int input) {
    int ceilAns = -1;
    
    Node *curr = root;
    while(curr != NULL) {
        if(curr -> data == input) {
            return curr -> data;
        }
        else if(curr -> data > input) {
            ceilAns = curr -> data;
            curr = curr -> left;
        }
        else {
            curr = curr -> right;
        }
    }
    
    return ceilAns;
}