/**
 * The function performs an iterative inorder traversal on a binary tree using Morris Traversal
 * algorithm to return the nodes in sorted order.
 * 
 * @param root The function `inorderTraversal` performs an iterative inorder traversal of a binary tree
 * starting from the given `root` node. The algorithm uses Morris Traversal, which allows for inorder
 * traversal without using a stack or recursion.
 * 
 * @return The function `inorderTraversal` returns a vector of integers containing the inorder
 * traversal of the binary tree rooted at the input `root` node.
 */
vector<int> inorderTraversal(TreeNode* root) {
    vector <int> res;

    if(root == NULL) return res;

    TreeNode *curr = root;

    while(curr != NULL) {
        if(curr -> left == NULL) {
            // It means this is root node so we print and move to right
            res.push_back(curr -> val);
            curr = curr -> right;
        }
        else {
            // We go to left subtree
            TreeNode *temp = curr -> left;
            
            // Finding the rightmost last node which has 
            // temp -> right == NULL in left subtree of curr
            while(temp -> right != NULL && temp -> right != curr) {
                temp = temp -> right;
            }

            // Thread already exists, so remove that thread and move to right
            if(temp -> right == curr) {
                // As we revisted again, this is root node
                res.push_back(curr -> val);
                temp -> right = NULL;
                curr = curr -> right;
            }
            // Creating thread, as it doesn't exists 
            else if(temp -> right == NULL) {
                temp -> right = curr;
                curr = curr -> left;
            }
        }
    }

    return res;
}