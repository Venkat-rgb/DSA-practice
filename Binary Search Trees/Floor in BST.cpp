/**
 * The function "floor" finds the largest value in a binary search tree that is less than or equal to a
 * given value x.
 * 
 * @param root The `root` parameter is a pointer to the root node of a binary search tree. The function
 * `floor` is designed to find the largest value in the tree that is less than or equal to the given
 * value `x`.
 * @param x The function `floor` takes in a binary search tree `root` and an integer `x`. It finds the
 * largest value in the tree that is less than or equal to `x`. If there is no such value, it returns
 * -1.
 * 
 * @return The function `floor` is returning the largest value in the binary search tree that is less
 * than or equal to the given value `x`. If the given value `x` is found in the tree, then that value
 * is returned. If the given value `x` is not found in the tree, then the largest value less than `x`
 * is returned. If the tree is empty (root
 */
int floor(Node* root, int x) {
    if(root == NULL) return -1;
    
    int maxi = -1;
    Node *curr = root;
    
    while(curr != NULL) {
        if(curr -> data == x) {
            return curr -> data;
        }
        else if(curr -> data < x) {
            maxi = max(maxi, curr -> data);
            curr = curr -> right;
        }
        else {
            curr = curr -> left;
        }
    }
    
    return maxi;
}