/**
 * The function `changeTree` modifies the values of nodes in a binary tree based on the sum of its
 * children nodes.
 * 
 * @param root The function `changeTree` takes a pointer to the root of a binary tree as a parameter.
 * The binary tree is represented using nodes where each node contains an integer value and pointers to
 * its left and right children. The function modifies the values of the nodes in the tree based on the
 * sum of values
 * 
 * @return The function `changeTree` does not have a return value specified, so it does not explicitly
 * return anything. It is a void function, meaning it does not return any value.
 */
void changeTree(BinaryTreeNode < int > * root) {
    if(root == NULL) return;

    int sum = 0;
    if(root -> left != NULL) {
        sum += root -> left -> data;
    }
    if(root -> right != NULL) {
        sum += root -> right -> data;
    }

    if(sum > root -> data) {
        root -> data = sum;
    }
    else if(sum < root -> data) {
        if(root -> left != NULL) {
            root -> left -> data = root -> data;
        }   
        if(root -> right != NULL) {
            root -> right -> data = root -> data;
        }
    }

    changeTree(root -> left);
    changeTree(root -> right);

    int total = 0;
    if(root -> left != NULL) total += root -> left -> data;
    if(root -> right != NULL) total += root -> right -> data;
   // We should not change node data if the node is a leaf node
    if(root -> left != NULL || root -> right != NULL) {
        root -> data = total;
    }
}