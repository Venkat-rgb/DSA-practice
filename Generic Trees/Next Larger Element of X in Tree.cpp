TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    if(root == NULL) return root;

    TreeNode <int> *minNode = NULL;

    if(root -> data > x) {
        minNode = root;
    }

    for(int i = 0; i < root -> children.size(); ++i) {
        TreeNode <int> *res = getNextLargerElement(root -> children[i], x);
        if(res != NULL) {
            if(minNode == NULL) {
                minNode = res;
            }
            else {
                if(minNode -> data > res -> data) {
                    minNode = res;
                }
            }
        }
    }

    return minNode;
}