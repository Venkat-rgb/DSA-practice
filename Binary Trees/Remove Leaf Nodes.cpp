BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
	if(root == NULL) return root;

	BinaryTreeNode <int> *leftTree = removeLeafNodes(root -> left);
	BinaryTreeNode <int> *rightTree = removeLeafNodes(root -> right);

	if(root -> left == NULL && root -> right == NULL) {
		delete root;
		return NULL;
	}

	return root;
}