/**
 * The function `kthAncestor` finds the k-th ancestor of a given node in a binary tree.
 * 
 * @param root The `root` parameter in the `kthAncestorHelper` function represents the root of the
 * binary tree where you want to find the k-th ancestor of a given node.
 * @param node The `node` parameter in the `kthAncestorHelper` function represents the node value for
 * which we want to find the kth ancestor. In the `kthAncestor` function, it is the node value for
 * which we want to find the kth ancestor in the binary tree rooted
 * @param count The `count` parameter in the `kthAncestorHelper` function is used to keep track of the
 * number of ancestors encountered while traversing the tree. It is incremented each time an ancestor
 * is found. This count is compared with the value of `k` to determine if the current ancestor is
 * @param k The parameter `k` in the `kthAncestor` function represents the distance of the ancestor
 * from the given node. It specifies which ancestor you are interested in finding, such as the 1st
 * ancestor, 2nd ancestor, and so on.
 * @param ancestor The `ancestor` parameter in the `kthAncestorHelper` function is used to store the
 * value of the k-th ancestor of the given node. It is passed by reference so that its value can be
 * updated within the function and then accessed outside the function in the `kthAncestor`
 * 
 * @return The function `kthAncestor` is returning the k-th ancestor of a given node in a binary tree.
 * If the k-th ancestor exists, it returns the value of that ancestor; otherwise, it returns -1.
 */

bool kthAncestorHelper(Node *root, int node, int &count, int k, int &ancestor) {
    if(root == NULL) return false;
    
    bool leftRes = kthAncestorHelper(root -> left, node, count, k, ancestor);
    bool rightRes = kthAncestorHelper(root -> right, node, count, k, ancestor);
    
    if(root -> data == node) return true;
    
    if(leftRes || rightRes) {
        if(count == k) {
            ancestor = root -> data;
        }
        count++;
        return true;
    }        
    
    return false;
}

int kthAncestor(Node *root, int k, int node) {
    int count = 0, ancestor = -1;
    
    kthAncestorHelper(root, node, count, k - 1, ancestor);
    
    return ancestor == -1 ? -1 : ancestor;
}