/**
 * The function `isSumTree` checks if a binary tree is a sum tree, where each node's value is equal to
 * the sum of its children's values.
 * 
 * @param root The `root` parameter in the `sumHelper` function represents the root of a binary tree
 * node. The `Node` structure likely contains an integer `data` field representing the value of the
 * node, and pointers to the left and right child nodes.
 * 
 * @return The function `isSumTree` is returning a boolean value, which indicates whether the given
 * binary tree is a Sum Tree or not.
 */
pair <int, bool> sumHelper(Node *root) {
    if(root == NULL) return {0, true};
    if(root -> left == NULL && root -> right == NULL) {
        return {root -> data, true};
    }
    
    pair <int, bool> leftAns = sumHelper(root -> left);
    pair <int, bool> rightAns = sumHelper(root -> right);
    
    int totalSum = root -> data + leftAns.first + rightAns.first;
    bool isSum = leftAns.second && rightAns.second && (root -> data == leftAns.first + rightAns.first);
    
    return {totalSum, isSum};
}

bool isSumTree(Node* root) {
    return sumHelper(root).second;  
}
