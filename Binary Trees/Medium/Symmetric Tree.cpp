bool symmetricHelper(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL)
            return true;

        queue<TreeNode*> q;
        q.push(root1);
        q.push(root2);

        while (!q.empty()) {
            TreeNode* frontNode1 = q.front();
            q.pop();
            TreeNode* frontNode2 = q.front();
            q.pop();

            if (frontNode1 == NULL && frontNode2 == NULL)
                continue;

            if (frontNode1 == NULL || frontNode2 == NULL ||
                frontNode1->val != frontNode2->val)
                return false;

            q.push(frontNode1 -> left);
            q.push(frontNode2 -> right);
            q.push(frontNode1 -> right);
            q.push(frontNode2 -> left);
        }

        return true;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;

        return symmetricHelper(root->left, root->right);
    }