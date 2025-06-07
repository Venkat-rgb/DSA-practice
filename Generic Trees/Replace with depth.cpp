void helper(TreeNode <int> *root, int depth) {
    for(int i = 0; i < root -> children.size(); ++i) {
        helper(root -> children[i], depth + 1);
    }

    root -> data = depth;
}

void replaceWithDepthValue(TreeNode<int>* root) {
    if(root == NULL) return;
    helper(root, 0);
}