/**
 * The given C++ function `topView` performs a depth-first search on a binary tree to find the top view
 * of the tree and returns a vector of integers representing the top view nodes.
 * 
 * @param root The `root` parameter is a pointer to the root node of a binary tree. This function is
 * designed to perform a Depth First Search (DFS) traversal on the binary tree starting from the root
 * node.
 * @param level The `level` parameter in the `dfs` function represents the level of the current node in
 * the binary tree. It starts at 0 for the root node and increments by 1 as we move down the tree
 * during the depth-first search traversal.
 * @param vertical The `vertical` parameter in the `dfs` function represents the vertical distance of
 * the current node from the root node. It is used to keep track of the horizontal position of each
 * node in the binary tree. Positive values indicate nodes to the right of the root, while negative
 * values indicate nodes to the
 * @param mp The `mp` parameter in the `dfs` function is a `map` that stores the vertical level as the
 * key and a pair of values as the value. The pair consists of the data value of the node at that
 * vertical level and the level of that node in the tree. This map is
 * 
 * @return The function `topView` returns a vector of integers, which represents the top view of the
 * binary tree starting from the given root node.
 */
void dfs(Node *root, int level, int vertical, map <int, pair<int,int>> &mp) {
        if(root == NULL) return;
        
        if(mp.find(vertical) == mp.end() || mp[vertical].second > level) {
            mp[vertical] = {root -> data, level};
        }
        
        dfs(root -> left, level + 1, vertical - 1, mp);
        dfs(root -> right, level + 1, vertical + 1, mp);
    }
    
    
    vector<int> topView(Node *root) {
        vector <int> res;
        
        if(root == NULL) return res;
        
        map <int, pair<int,int>> mp;
        
        dfs(root, 0, 0, mp);
        
        for(auto it : mp) {
            res.push_back(it.second.first);
        }
        
        return res;
    }