bool rootToNodePath(BinaryTree <int> *root, vector <int> &path, int target) {
    if(root == NULL) return false;
    
    path.push_back(root -> data);
    
    if(root -> data == target) return true;
    
    bool targetFoundOnLeft = rootToNodePath(root -> left, path, target);
    if(targetFoundOnLeft) return true;
    
    bool targetFoundOnRight = rootToNodePath(root -> right, path, target);
    if(targetFoundOnRight) return true;
    
    path.pop_back();
    return false;
}