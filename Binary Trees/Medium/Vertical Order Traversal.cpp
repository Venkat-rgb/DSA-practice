void dfs(TreeNode *root, int depth, int vertical, map <int, map<int, multiset<int>>> &mp) {
        if(root == NULL) return;

        mp[col][row].insert(root -> val);
        dfs(root -> left, depth + 1, vertical - 1, mp);
        dfs(root -> right, depth + 1, vertical + 1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;

        if(root == NULL) return res;

        map <int, map <int, multiset<int>>> mp;

        // Fills the map recursively, everthing else is same as in BFS
        dfs(root, 0, 0, mp);

        for(auto it1 : mp) {
            vector <int> temp;
            for(auto it2 : it1.second) {
                for(auto i : it2.second) {
                    temp.push_back(i);
                }
            }
            res.push_back(temp);
        }

        return res;
    }