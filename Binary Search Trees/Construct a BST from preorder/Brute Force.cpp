/* This C++ class constructs a Binary Search Tree (BST) from a given preorder traversal of its nodes. */
class Solution {
public:
    TreeNode* constructBST(vector <int> &preorder, int &start, int minimum, int maximum) {
        if(start == preorder.size() || preorder[start] <= minimum || preorder[start] >= maximum) {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[start++]);
        root -> left = constructBST(preorder, start, minimum, root -> val);
        root -> right = constructBST(preorder, start, root -> val, maximum);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int start = 0;
        return constructBST(preorder, start, INT_MIN, INT_MAX);
    }
};