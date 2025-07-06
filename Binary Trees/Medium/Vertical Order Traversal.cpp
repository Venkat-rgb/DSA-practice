/**
 * The function `verticalTraversal` performs a depth-first search on a binary tree to create a vertical
 * traversal of the tree nodes.
 * 
 * @param root The `root` parameter is a pointer to the root node of a binary tree. The function `dfs`
 * performs a depth-first search traversal of the binary tree starting from the root node.
 * @param depth The `depth` parameter in the `dfs` function represents the current depth level of the
 * tree node being processed. It is incremented by 1 for each level deeper in the recursive calls. This
 * parameter helps in tracking the depth of each node in the tree during the traversal process.
 * @param vertical The `vertical` parameter in the `dfs` function represents the vertical position of
 * the current node relative to the root node. It is used to track the vertical position of each node
 * in the binary tree as we traverse it recursively. Positive values indicate nodes to the right of the
 * root, while negative values
 * @param mp The `mp` parameter in the `dfs` function is a map that stores the values of the tree nodes
 * based on their vertical and horizontal positions. It is defined as `map<int, map<int,
 * multiset<int>>> mp`, where:
 * 
 * @return The function `verticalTraversal` is returning a vector of vectors of integers, where each
 * inner vector represents the values of nodes at a specific vertical level in the binary tree.
 */
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