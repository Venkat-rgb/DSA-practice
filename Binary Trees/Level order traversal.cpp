#include <queue>

void printLevelWise(BinaryTreeNode<int> *root) {
    if(root == NULL) return;

	queue <BinaryTreeNode<int>*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		BinaryTreeNode <int> *frontNode = q.front();

		if(frontNode == NULL) {
			if(q.size() == 1) {
				return;
			}
			cout << endl;
			q.push(NULL);
		}
		else {
			cout << frontNode -> data << " ";	

			if(frontNode -> left != NULL) {
				q.push(frontNode -> left);
			}
			if(frontNode -> right != NULL) {
				q.push(frontNode -> right);
			}
		}
		q.pop();
	}
}