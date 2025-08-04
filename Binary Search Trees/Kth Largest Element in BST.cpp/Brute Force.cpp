/**
 * The function `kthLargest` finds the kth largest element in a binary search tree.
 * 
 * @param root The `root` parameter is a pointer to the root node of a binary search tree (BST) from
 * which we want to find the kth largest element.
 * @param k The parameter `k` in the `kthLargest` function represents the position of the kth largest
 * element that we want to find in the binary search tree. It is used to determine which largest
 * element we are looking for in the tree.
 * @param cnt The `cnt` parameter in the `kthLargestHelper` function is used to keep track of the
 * number of nodes visited while traversing the binary search tree in reverse order (right, root,
 * left). It is incremented each time a node is visited, and when `cnt` becomes equal
 * @param res The `res` parameter in the `kthLargestHelper` function is used to store the value of the
 * kth largest element found in the binary search tree. It is passed by reference so that the value can
 * be updated within the function and then accessed in the `kthLargest`
 * 
 * @return The function `kthLargest` returns the kth largest element in a binary search tree
 * represented by the `Node *root`.
 */
void kthLargestHelper(Node *root, int k, int &cnt, int &res) {
    if(root == NULL) return;
    
    kthLargestHelper(root -> right, k, cnt, res);
    cnt++;
    if(cnt == k) {
        res = root -> data;
        return;
    }
    kthLargestHelper(root -> left, k, cnt, res);
}
    
int kthLargest(Node *root, int k) {
    int cnt = 0, res = -1;
    kthLargestHelper(root, k, cnt, res);
    return res;
}