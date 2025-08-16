/* The `Solution` class contains a method to find the size of the largest sub-tree that is also a
Binary Search Tree (BST). */
class Info {
public:  
    bool isBST;
    int nodeCnt;
    int minimum;
    int maximum;
};

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    Info checkBST(Node *root, int &maxCnt) {
        if(root == NULL) return {true, 0, INT_MAX, INT_MIN};
        
        Info leftRes = checkBST(root -> left, maxCnt);
        Info rightRes = checkBST(root -> right, maxCnt);
        
        int totalCnt = 1 + leftRes.nodeCnt + rightRes.nodeCnt;
        int minimum = min(root -> data, leftRes.minimum);
        int maximum = max(root -> data, rightRes.maximum);
        
        if(leftRes.isBST && rightRes.isBST && root -> data > leftRes.maximum && root -> data < rightRes.minimum) {
            maxCnt = max(maxCnt, totalCnt);
            return {true, totalCnt, minimum, maximum};
        }
        
        return {false, totalCnt, minimum, maximum};
    }
    
    
    int largestBst(Node *root) {
        int maxCnt = 0;
        checkBST(root, maxCnt);
        return maxCnt;
    }
};