/**
 * The function `rootToNodePath` recursively finds a path from the root of a binary tree to a node with
 * a specific target value.
 * 
 * @param root The `root` parameter is a pointer to the root node of a binary tree.
 * @param path The `path` parameter is a vector that stores the path from the root of the binary tree
 * to a target node. It is passed by reference to the function `rootToNodePath` so that the path can be
 * updated and maintained as the function traverses the tree to find the target node.
 * @param target The `target` parameter in the `rootToNodePath` function represents the value that we
 * are searching for in the binary tree. The function aims to find a path from the root node to a node
 * containing the target value. If such a path exists, the function will populate the `path`
 * 
 * @return The function `rootToNodePath` returns a boolean value indicating whether a path from the
 * root to a node with the target value exists in the binary tree.
 */
bool rootToNodePath(BinaryTree <int> *root, vector <int> &path, int target) {
    if(root == NULL) return false;
    
    path.push_back(root -> data);
    s
    if(root -> data == target) return true;
    
    bool targetFoundOnLeft = rootToNodePath(root -> left, path, target);
    if(targetFoundOnLeft) return true;
    
    bool targetFoundOnRight = rootToNodePath(root -> right, path, target);
    if(targetFoundOnRight) return true;
    
    path.pop_back();
    return false;
}