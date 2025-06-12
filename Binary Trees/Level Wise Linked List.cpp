vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
	if(root == NULL) {
		return {NULL};
	}

    vector <Node<int>*> res;
	queue <BinaryTreeNode<int>*> q;
	q.push(root);

	while(!q.empty()) {
		int levelSize = q.size();

		Node <int> *dummy = new Node<int>(-1);
		Node <int> *dummyHead = dummy;

		for(int i = 0; i < levelSize; ++i) {
			BinaryTreeNode <int> *frontNode = q.front();
			q.pop();

			dummy -> next = new Node<int>(frontNode -> data);
			dummy = dummy -> next;

			if(frontNode -> left != NULL) {
				q.push(frontNode -> left);
			}

			if(frontNode -> right != NULL) {
				q.push(frontNode -> right);
			}
		}

		res.push_back(dummyHead -> next);
	}

	return res;
}