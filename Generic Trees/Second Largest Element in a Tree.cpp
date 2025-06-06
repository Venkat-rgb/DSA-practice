int getMax(TreeNode <int> *root) {
    if(root == NULL) return 0;

    int maxi = root -> data;

    for(int i = 0; i < root -> children.size(); ++i) {
        int res = getMax(root -> children[i]);
        if(res > maxi) {
            maxi = res;
        }
    }

    return maxi;
}

TreeNode <int> *secondLargestNodeHelper(TreeNode <int> *root, int maxVal) {
    TreeNode <int> *secondMax = NULL;

    if(root -> data < maxVal) {
        secondMax = root;
    }

    for(int i = 0; i < root -> children.size(); ++i) {
        TreeNode <int> *res = secondLargestNodeHelper(root -> children[i], maxVal);
        if(res != NULL) {
            if(secondMax == NULL) {
                secondMax = res;
            }
            else {
                if(res -> data > secondMax -> data) {
                    secondMax = res;
                }
            }
        }
    }

    return secondMax;
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    if(root == NULL) return root;
    int maxVal = getMax(root);
    return secondLargestNodeHelper(root, maxVal);
}