/**
 * The function `pseudoPalindromicPaths` calculates the number of pseudo-palindromic paths in a binary
 * tree where a pseudo-palindromic path is a path in which the frequency of each digit is at most one
 * odd number.
 * 
 * @param root The `root` parameter in the given code represents the root of a binary tree. The code is
 * designed to find the number of pseudo-palindromic paths in the binary tree. Each path in the tree is
 * considered pseudo-palindromic if it can be rearranged to form a
 * @param oddCnt The `oddCnt` parameter in the `palindromicHelper` function is used to keep track of
 * the count of odd occurrences of each digit in the path being traversed. It is updated by XORing the
 * current value of `oddCnt` with the bit corresponding to the value of the
 * @param pathCnt The `pathCnt` parameter is an integer reference that is used to keep track of the
 * number of pseudo-palindromic paths found in the binary tree. It is initially set to 0 in the
 * `pseudoPalindromicPaths` function and is passed by reference to the `pal
 * 
 * @return The function `pseudoPalindromicPaths` is returning the number of pseudo-palindromic paths in
 * the binary tree rooted at `root`.
 */
void palindromicHelper(TreeNode *root, int oddCnt, int &pathCnt) {
    if(root == NULL) return;

    oddCnt = oddCnt ^ (1 << root -> val);

    if(root -> left == NULL && root -> right == NULL) {
        if((oddCnt & (oddCnt - 1)) == 0) pathCnt++;
    }

    palindromicHelper(root -> left, oddCnt, pathCnt);
    palindromicHelper(root -> right, oddCnt, pathCnt);
}

int pseudoPalindromicPaths(TreeNode* root) {
    if(root == NULL) return 0;

    int pathCnt = 0;

    palindromicHelper(root, 0, pathCnt);

    return pathCnt;
}