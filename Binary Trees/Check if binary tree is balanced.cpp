int treeHeight(BinaryTreeNode <int> *root) {
	if(root == NULL) return 0;

	int leftHeight = treeHeight(root -> left);
	int rightHeight = treeHeight(root -> right);

	return 1 + max(leftHeight, rightHeight);
}

bool isBalanced(BinaryTreeNode<int> *root) {
	if(root == NULL) return true;
	
	// My work
	int leftSubtreeHeight = treeHeight(root -> left);
	int rightSubtreeHeight = treeHeight(root -> right);

	if(abs(leftSubtreeHeight - rightSubtreeHeight) > 1) {
		return false;
	}

	return isBalanced(root -> left) && isBalanced(root -> right);
}