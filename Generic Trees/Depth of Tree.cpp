void depthOfTree(Tree <int> *root, int k) {
    if(root == NULL) return;
    
    if(k == 0) {
        cout << root -> data << " ";
        return;
    }
    
    for(int i = 0; i < root -> children.size(); ++i) {
        depthOfTree(root -> children[i], k - 1);
    }
}