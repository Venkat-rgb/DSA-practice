/**
 * The function `deleteNode` in C++ deletes a node with a given key from a binary search tree while
 * maintaining the binary search tree properties.
 * 
 * @param root The function `deleteNode` takes in a binary search tree represented by its root node
 * `root`, and an integer `key` that needs to be deleted from the tree. The function then searches for
 * the key in the tree and deletes it while maintaining the properties of a binary search tree.
 * @param key The function `deleteNode` is a C++ function that deletes a node with a specific key from
 * a binary search tree. The `key` parameter represents the value of the node that needs to be deleted
 * from the tree. The function traverses the tree to find the node with the specified key and
 * 
 * @return The function `deleteNode` returns a `TreeNode*`, which is the root of the binary search tree
 * after deleting the node with the specified key.
 */
TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == NULL) return root;

    // 1) Search for key and also store its parent
    TreeNode *curr = root, *parent = NULL;
    
    while(curr != NULL && curr -> val != key) {
        parent = curr;
        
        if(curr -> val > key) {
            curr = curr -> left;
        }
        else {
            curr = curr -> right;
        }
    }
    
    // 2) If key doesn't exist, then return NULL
    if(!curr) {
        return root;
    }
    
    // 3) If key has only one child
    if(curr -> left == NULL || curr -> right == NULL) {
        TreeNode *newCurr = curr -> left == NULL ? curr -> right : curr -> left;
        
        // If key is root node
        if(parent == NULL) {
            delete curr;
            return newCurr;
        }
        
        if(parent -> val > curr -> val) {
            parent -> left = newCurr;
        }
        else {
            parent -> right = newCurr;
        }
        
        delete curr;
        return root;
    }
    
    // 4) If key has 2 childs, then find the successor node and its parent
    TreeNode *sucNode = curr -> right, *sucParent = NULL;
    
    while(sucNode -> left != NULL) {
        sucParent = sucNode;
        sucNode = sucNode -> left;
    }
    
    // Replacing the key node with successor value
    curr -> val = sucNode -> val;
    
    TreeNode *sucChild = sucNode -> right;
    
    if(sucParent == NULL) {
        curr -> right = sucChild;
    }
    else {
        sucParent -> left = sucChild;
    }
    
    delete sucNode;
    return root;
}