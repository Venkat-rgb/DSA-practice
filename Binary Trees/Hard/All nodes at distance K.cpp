/**
 * The function `distanceK` finds all nodes at a distance `k` from a given target node in a binary
 * tree.
 * 
 * @param root The `root` parameter in the given code represents the root of a binary tree.
 * @param parent The `parent` parameter in the `markParents` function is a pointer to the parent node
 * of the current node being processed. It is used to keep track of the parent-child relationships in
 * the binary tree while traversing it recursively.
 * @param parentMp The `parentMp` parameter is an unordered map that stores the parent of each node in
 * the binary tree. This map is used to keep track of the parent-child relationships in the tree while
 * traversing it. The keys in the map are the child nodes, and the values are their respective parent
 * nodes
 * 
 * @return The function `distanceK` returns a vector of integers containing the values of nodes that
 * are at a distance `k` from the target node in a binary tree.
 */
void markParents(TreeNode* root, TreeNode* parent,
                     unordered_map<TreeNode*, TreeNode*>& parentMp) {
    if (root == NULL)
        return;

    parentMp[root] = parent;
    markParents(root->left, root, parentMp);
    markParents(root->right, root, parentMp);
}

void distanceKHelper(TreeNode* root, int k,
                        unordered_set<TreeNode*>& visited,
                        unordered_map<TreeNode*, TreeNode*>& parentMp,
                        vector<int>& res) {
    if (root == NULL || visited.find(root) != visited.end())
        return;

    visited.insert(root);

    if (k == 0) {
        res.push_back(root->val);
        return;
    }

    // Left
    distanceKHelper(root->left, k - 1, visited, parentMp, res);

    // Right
    distanceKHelper(root->right, k - 1, visited, parentMp, res);

    // Top
    distanceKHelper(parentMp[root], k - 1, visited, parentMp, res);
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parentMp;

    markParents(root, NULL, parentMp);

    unordered_set<TreeNode*> visited;
    vector<int> res;

    distanceKHelper(target, k, visited, parentMp, res);

    return res;
}