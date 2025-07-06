/**
 * The function `leftView` returns the left view of a binary tree using depth-first search.
 * 
 * @param root The `root` parameter is a pointer to the root node of a binary tree.
 * @param level The `level` parameter in the `dfs` function represents the current level or depth of
 * the node in the binary tree. It is used to keep track of the level of each node while performing a
 * depth-first search traversal. The level starts at 0 for the root node and increments as we move
 * @param res `res` is a reference to a vector of integers that will store the left view of the binary
 * tree. The `dfs` function is used to perform a depth-first search traversal of the binary tree and
 * populate the `res` vector with the leftmost nodes at each level of the tree. The
 * 
 * @return The function `leftView` is returning a vector of integers, which contains the left view of
 * the binary tree starting from the root node.
 */
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