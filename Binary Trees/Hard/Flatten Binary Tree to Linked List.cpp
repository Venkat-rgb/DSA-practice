/**
 * The flatten function modifies a binary tree by rearranging the nodes to form a flattened structure
 * where each node's left child points to NULL and the right child points to the next node in a
 * pre-order traversal.
 * 
 * @param root The `root` parameter in the `flatten` function is a pointer to the root of a binary tree
 * represented using the following TreeNode structure:
 * 
 * @return The function `flatten` does not return any value as it has a return type of `void`. It
 * modifies the binary tree structure in place by flattening it into a linked list in preorder
 * traversal order.
 */
void flattenBinaryTree(TreeNode* root) {
    if(root == NULL) return;

    TreeNode *curr = root;

    while(curr != NULL) {
        if(curr -> left == NULL) {
            curr = curr -> right;
        }
        else {
            // Finding the last visited node in preorder which is right
            // So finding the rightmost last node of left subtree
            TreeNode *temp = curr -> left;
            while(temp -> right != NULL) {
                temp = temp -> right;
            }

            temp -> right = curr -> right;
            curr -> right = curr -> left;
            curr -> left = NULL;
            curr = curr -> right;
        }
    }
}