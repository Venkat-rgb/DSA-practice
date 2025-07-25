void preOrder(TreeNode *root, vector <int> &res) {
        if(root == NULL) return;

        res.push_back(root -> val);
        preOrder(root -> left, res);
        preOrder(root -> right, res);
    } 

    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> res;
        if(root == NULL) return res;
        preOrder(root, res);
        return res;
    }