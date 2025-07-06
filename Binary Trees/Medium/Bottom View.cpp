/**
 * The given C++ function performs a depth-first search to find the bottom view of a binary tree and
 * returns the values of nodes visible from the bottom.
 * 
 * @param root The `root` parameter is a pointer to the root node of a binary tree.
 * @param level The `level` parameter in the `dfs` function represents the level of the current node in
 * the binary tree. It is used to keep track of the depth of the current node while traversing the tree
 * in a depth-first manner. The level starts at 0 for the root node and increments as
 * @param vertical The `vertical` parameter in the `dfs` function represents the vertical distance of
 * the current node from the root node. It is used to keep track of the horizontal position of each
 * node in the binary tree. Positive values indicate nodes to the right of the root, while negative
 * values indicate nodes to the
 * @param mp The `mp` parameter in the `dfs` function is a `map<int, pair<int, int>>` which is used to
 * store the bottom view of the binary tree nodes. The key of the map represents the vertical distance
 * of the node from the root, and the value is a pair where
 * 
 * @return The function `bottomView` returns a vector of integers, which represents the bottom view of
 * the binary tree starting from the given root node.
 */
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