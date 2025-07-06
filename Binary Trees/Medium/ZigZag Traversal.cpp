/**
 * The function `zigzagLevelOrder` performs a level order traversal of a binary tree in a zigzag
 * pattern and returns the nodes in each level in a vector of vectors.
 * 
 * @param root The provided code is a function that performs a level order traversal of a binary tree
 * in a zigzag pattern. The function takes a TreeNode pointer `root` as input, which represents the
 * root of the binary tree for which the zigzag level order traversal needs to be performed.
 * 
 * @return The function `zigzagLevelOrder` returns a vector of vectors of integers, which represents
 * the level order traversal of a binary tree in a zigzag pattern.
 */
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