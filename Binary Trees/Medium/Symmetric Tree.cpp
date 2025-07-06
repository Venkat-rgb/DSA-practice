/**
 * The given C++ function checks if a binary tree is symmetric by comparing the left and right subtrees
 * recursively.
 * 
 * @param root1 The `root1` parameter in the `symmetricHelper` function represents the root of the left
 * subtree of the binary tree being checked for symmetry. It is used to traverse the left subtree in a
 * mirrored fashion along with the `root2` parameter, which represents the root of the right subtree.
 * @param root2 `root2` is a pointer to the root of the second subtree that needs to be checked for
 * symmetry with the first subtree rooted at `root1`.
 * 
 * @return The code snippet provided contains two functions. The `symmetricHelper` function is a helper
 * function that checks if two subtrees are symmetric. The `isSymmetric` function checks if the entire
 * tree is symmetric by calling the `symmetricHelper` function on the left and right subtrees of the
 * root node.
 */
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