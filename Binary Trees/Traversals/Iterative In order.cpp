vector<int> inorderTraversal(TreeNode* root) {
        vector <int> res;

        if (root == NULL)
            return res;

        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != NULL || !st.empty()) {
            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* frontNode = st.top();
                st.pop();
                res.push_back(frontNode->val);
                if (frontNode->right != NULL) {
                    curr = frontNode->right;
                }
            }
        }

        return res;
    }