void dfs(Node *root, int level, int vertical, map <int, pair<int,int>> &mp) {
        if(root == NULL) return;
        
        if(mp.find(vertical) == mp.end() || level >= mp[vertical].second) {
            mp[vertical] = {root -> data, level};
        }
        
        dfs(root -> left, level + 1, vertical - 1, mp);
        dfs(root -> right, level + 1, vertical + 1, mp);
    }
  
    vector<int> bottomView(Node *root) {
        vector <int> res;
        
        if(root == NULL) return res;
        
        map <int, pair<int,int>> mp;
        dfs(root, 0, 0, mp);
        
        for(auto &it : mp) {
            res.push_back(it.second.first);
        }
        
        return res;
    }