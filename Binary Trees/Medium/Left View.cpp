void dfs(Node *root, int level, vector <int> &res) {
        if(root == NULL) return;

        if(level == res.size()) {
            res.push_back(root -> data);
        }

        dfs(root -> left, level + 1, res);
        dfs(root -> right, level + 1, res);
    }
  
    vector<int> leftView(Node *root) {
        vector <int> res;
        
        if(root == NULL) return res;
        
        dfs(root, 0, res);
        
        return res;
    }