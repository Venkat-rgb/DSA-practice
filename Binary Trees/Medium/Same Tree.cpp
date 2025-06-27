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