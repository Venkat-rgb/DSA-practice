/**
 * The function `findClosestLeafNodeDistance` calculates the minimum distance from a given node `x` to
 * the closest leaf node in a binary tree.
 * 
 * @param root The `root` parameter in the `findClosestLeafHelper` function represents the root of a
 * binary tree where you are searching for the closest leaf node to a given value `x`.
 * @param x The parameter `x` in the `findClosestLeafNodeDistance` function represents the value of the
 * node for which you want to find the closest leaf node distance in the binary tree.
 * @param minDistance The `minDistance` parameter in the `findClosestLeafHelper` function is used to
 * keep track of the minimum distance from the node containing value `x` to the closest leaf node in
 * the binary tree. It is passed by reference so that its value can be updated and maintained across
 * recursive calls
 * 
 * @return The function `findClosestLeafNodeDistance` returns the minimum distance from the node with
 * value `x` to the closest leaf node in the binary tree.
 */
int findClosestLeafHelper(BinaryTreeNode <int> *root, int x, int &minDistance) {
    if(root == NULL) return 0;

    if(root -> left == NULL) {
        int rightHeight = findClosestLeafHelper(root -> right, x, minDistance);
        if(root -> data == x) {
            minDistance = rightHeight;
            return -1;
        }   
        else if(rightHeight >= 0) {
            return 1 + rightHeight;
        }     
        else if(rightHeight < 0) {
            return rightHeight - 1;
        }
    }

    if(root -> right == NULL) {
        int leftHeight = findClosestLeafHelper(root -> left, x, minDistance);
        if(root -> data == x) {
            minDistance = leftHeight;
            return -1;
        }   
        else if(leftHeight >= 0) {
            return 1 + leftHeight;
        }     
        else if(leftHeight < 0) {
            return leftHeight - 1;
        }
    }

    int leftHeight = findClosestLeafHelper(root -> left, x, minDistance);
    int rightHeight = findClosestLeafHelper(root -> right, x, minDistance);   

    if(root -> data == x) {
        minDistance = min(leftHeight, rightHeight);
        return -1;
    } 
    else if(leftHeight >= 0 && rightHeight >= 0) {
        return 1 + min(leftHeight, rightHeight);
    }
    else {
        minDistance = min(minDistance, abs(leftHeight) + abs(rightHeight));
        return min(leftHeight, rightHeight) - 1;
    }
}

int findClosestLeafNodeDistance(BinaryTreeNode<int> *root, int x) {
    int minDistance = INT_MAX;    

    findClosestLeafHelper(root, x, minDistance);

    return minDistance;
}