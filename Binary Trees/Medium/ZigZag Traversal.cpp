vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (root == NULL)
            return res;

        queue<TreeNode*> q;
        q.push(root);
        bool isLeftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();

            vector<int> temp(levelSize);

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* frontNode = q.front();
                q.pop();

                int idx = isLeftToRight ? i : levelSize - 1 - i;

                temp[idx] = frontNode -> val;

                if (frontNode->left != NULL) {
                    q.push(frontNode->left);
                }
                if (frontNode->right != NULL) {
                    q.push(frontNode->right);
                }
            }
            
            res.push_back(temp);
            isLeftToRight = !isLeftToRight;
        }

        return res;
    }