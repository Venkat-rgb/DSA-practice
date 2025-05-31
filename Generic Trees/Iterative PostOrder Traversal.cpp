vector<int> postorder(Node* root) {
        vector<int> res;

        if (root == NULL)
            return res;

        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* topNode = st.top();
            st.pop();

            res.push_back(topNode->val);

            for (int i = 0; i < topNode->children.size(); ++i) {
                st.push(topNode->children[i]);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }