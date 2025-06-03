pair <TreeNode<int>*, int> helper(TreeNode <int> *root) {
    TreeNode <int> *maxNode = root;
    int sum = root -> data;
    for(int i = 0; i < root -> children.size(); ++i) {
        sum += root -> children[i] -> data;
    }

    pair <TreeNode<int>*, int> ans(maxNode, sum);

    for(int i = 0; i < root -> children.size(); ++i) {
        pair <TreeNode<int>*, int> res = helper(root -> children[i]);
        if(res.second > ans.second) {
            ans.first = res.first;
        }
    }

    return ans;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    if(root == NULL) return root;
    pair <TreeNode<int>*, int> res = helper(root);
    return res.first;
}