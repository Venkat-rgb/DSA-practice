int getSum(BinaryTreeNode<int>* root) {
	if(root == NULL) return 0;

	int sum = root -> data;

	sum += getSum(root -> left);
	sum += getSum(root -> right);

	return sum;
}