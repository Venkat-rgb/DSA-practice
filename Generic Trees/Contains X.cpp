bool isPresent(TreeNode<int>* root, int x) {
    if(root == NULL) return false;

    for(int i = 0; i < root -> children.size(); ++i) {
        bool res = isPresent(root -> children[i], x);
        if(res) {
            return true;
        }
    }

    if(root -> data == x) return true;
    return false;
}