/**
 * The function `kthLargest` finds the kth largest element in a binary search tree.
 * 
 * @param root The `root` parameter in the function `kthLargest` is a pointer to the root node of a
 * binary search tree (BST). The function aims to find the kth largest element in the BST.
 * @param k The function `kthLargest` is designed to find the kth largest element in a binary search
 * tree. The parameter `k` represents the position of the element you want to find in descending order.
 * For example, if `k` is 1, it will return the largest element in
 * 
 * @return The function `kthLargest` returns the kth largest element in a binary search tree
 * represented by the given root node.
 */
int kthLargest(Node *root, int k) {
    int cnt = 0, res = -1;

    Node *curr = root;

    while(curr != NULL) {
        if(curr -> right == NULL) {
            cnt++;
            if(cnt == k) {
                res = curr -> data;
            }
            curr = curr -> left;
        }
        else {
            Node *temp = curr -> right;

            while(temp -> left != NULL && temp -> left != curr) {
                temp = temp -> left;
            }

            if(temp -> left == NULL) {
                temp -> left = curr;
                curr = curr -> right;
            }
            else {
                cnt++;
                if(cnt == k) {
                    res = curr -> data;
                }
                temp -> left = NULL;
                curr = curr -> left;
            }
        }
    }

    return res;
}