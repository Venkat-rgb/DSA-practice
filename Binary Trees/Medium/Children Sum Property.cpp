/**
 * The function `changeTree` modifies a binary tree such that each node's value is updated to the sum
 * of its children's values if the sum is greater than the node's original value.
 * 
 * @param root The function `changeTree` takes a pointer to a Binary Tree node as its parameter. The
 * Binary Tree node is defined as `BinaryTreeNode<int>` and is named `root` in this function. The
 * function modifies the values of the nodes in the tree based on certain conditions.
 * 
 * @return The function `changeTree` does not have a return value specified, so it does not explicitly
 * return anything. It is a void function, meaning it does not return any value. The function modifies
 * the binary tree structure by updating the node values based on certain conditions, but it does not
 * return any specific value.
 */
#include <bits/stdc++.h> 

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
    if(root -> left != NULL || root -> right != NULL) {
        root -> data = total;
    }
}