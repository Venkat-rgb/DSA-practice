/**
 * The function `isSameTree` in C++ checks if two binary trees are structurally identical and have the
 * same values at corresponding nodes.
 * 
 * @param p `p` is a pointer to the root of the first binary tree.
 * @param q The code snippet provided is a function that checks if two binary trees represented by
 * TreeNode pointers `p` and `q` are the same. It uses a breadth-first search approach with a queue to
 * compare the nodes of the trees level by level.
 * 
 * @return The function `isSameTree` is returning a boolean value. It returns `true` if the two input
 * binary trees `p` and `q` are structurally identical and have the same node values at corresponding
 * positions. Otherwise, it returns `false`.
 */
bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;

        queue <pair<TreeNode*, TreeNode*>> qu;
        qu.push({p, q});

        while(!qu.empty()) {
            TreeNode *pNode = qu.front().first;
            TreeNode *qNode = qu.front().second;
            qu.pop();

            if(pNode == NULL && qNode == NULL) continue;

            if(pNode == NULL || qNode == NULL || pNode -> val != qNode -> val) return false;

            qu.push({pNode -> left, qNode -> left});
            qu.push({pNode -> right, qNode -> right});
        }

        return true;
    }