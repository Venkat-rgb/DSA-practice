/**
 * The function `insertIntoBST` inserts a new node with a given value into a binary search tree while
 * maintaining the binary search tree property.
 * 
 * @param root The `root` parameter in the `insertIntoBST` function represents the root node of a
 * binary search tree where you want to insert a new node with the value `val`. The function traverses
 * the tree starting from the root node to find the correct position for the new node with the value `
 * @param val The `val` parameter in the `insertIntoBST` function represents the value that you want to
 * insert into the Binary Search Tree (BST). The function will create a new TreeNode with this value
 * and insert it into the correct position in the BST according to the rules of a binary search tree.
 * 
 * @return the root of the binary search tree after inserting the new node with value 'val'.
 */
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL) return new TreeNode(val);
    
    TreeNode *curr = root;

    while(true) {
        if(curr -> val > val) {
            if(curr -> left != NULL) {
                curr = curr -> left;
            }
            else {
                curr -> left = new TreeNode(val);;
                break;
            }
        }
        else {
            if(curr -> right != NULL) {
                curr = curr -> right;
            }
            else {
                curr -> right = new TreeNode(val);
                break;
            }
        }
    }

    return root;
}