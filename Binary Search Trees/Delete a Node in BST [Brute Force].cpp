/**
 * The function `deleteNode` in C++ deletes a node with a given key from a binary search tree while
 * maintaining the binary search tree properties.
 * 
 * @param root The `root` parameter in the `deleteNode` function represents the root of a binary search
 * tree (BST) from which you want to delete a node with a specific key value. The function recursively
 * searches for the node with the given key value and performs the deletion operation while maintaining
 * the properties of a
 * 
 * @return The function `deleteNode` returns a `TreeNode*` which represents the root of the updated
 * binary search tree after deleting the node with the specified key.
 */
TreeNode *successor(TreeNode *root) {
        while(root -> left != NULL) {
            root = root -> left;
        }
        return root;
    }

TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == NULL) return root;

    if(root -> val == key) {
        // 1) If single node
        if(root -> left == NULL && root -> right == NULL) {
            delete root;
            return NULL;
        }
        // 2) Skewed
        else if(root -> left == NULL) {
            TreeNode *rightNode = root -> right;
            root -> right = NULL;
            delete root;
            return rightNode;
        }
        else if(root -> right == NULL) {
            TreeNode *leftNode = root -> left;
            root -> left = NULL;
            delete root;
            return leftNode;
        }
        else {
            // 3) Node contains both childs, so we find preDeccessor
            TreeNode *successorNode = successor(root -> right);
            root -> val = successorNode -> val;
            root -> right = deleteNode(root -> right, successorNode -> val);
            return root;
        }
    }   

    if(root -> val > key) {
        root -> left = deleteNode(root -> left, key); 
    }   
    else {
        root -> right = deleteNode(root -> right, key);
    }

    return root;
}