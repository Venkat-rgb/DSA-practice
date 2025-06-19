vector<int> preorderTraversal(TreeNode* root) {
        vector <int> res;
        if(root == NULL) return res;

        stack <TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode *topNode = st.top();
            st.pop();

            res.push_back(topNode -> val);

            if(topNode -> right != NULL) {
                st.push(topNode -> right);
            }

            if(topNode -> left != NULL) {
                st.push(topNode -> left);
            }
        }

        return res;
    }