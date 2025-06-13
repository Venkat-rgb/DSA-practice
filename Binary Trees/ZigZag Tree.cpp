#include <queue>
void zigZagOrder(BinaryTreeNode<int> *root) {
	if (root == NULL)
		return;

	queue<BinaryTreeNode <int>*> q;
	q.push(root);
	bool isLeftToRight = true;

	while (!q.empty()) {
		int levelSize = q.size();

		vector<int> temp(levelSize);

		for (int i = 0; i < levelSize; ++i) {
			BinaryTreeNode <int> *frontNode = q.front();
			q.pop();

			int idx = isLeftToRight ? i : levelSize - 1 - i;

			temp[idx] = frontNode -> data;

			if (frontNode->left != NULL) {
				q.push(frontNode->left);
			}
			if (frontNode->right != NULL) {
				q.push(frontNode->right);
			}
		}
		
		for(int i = 0; i < temp.size(); ++i) {
			cout << temp[i] << " ";
		}
		cout << endl;

		isLeftToRight = !isLeftToRight;
	}
}