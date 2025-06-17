vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        if (root == NULL)
            return res;

        stack<TreeNode*> st;
        TreeNode* temp = root;

        while(true) {
            if(temp != NULL) {
                st.push(temp);
                temp = temp -> left;
            }
            else {
                if(st.empty()) break;

                TreeNode *topNode = st.top();
                st.pop();

                res.push_back(topNode -> val);
                temp = topNode -> right;
            }
        }

        return res;
    }