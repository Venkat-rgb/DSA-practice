int getLargeNodeCount(TreeNode<int>* root, int x) {
    if(root == NULL) return 0;

    int cnt = 0;

    if(root -> data > x) {
        cnt++;
    }

    for(int i = 0; i < root -> children.size(); ++i) {
        cnt += getLargeNodeCount(root -> children[i], x);
    }

    return cnt;
}