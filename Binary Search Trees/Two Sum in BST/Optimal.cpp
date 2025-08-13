/* The BSTIterator class provides an iterator for a binary search tree with the ability to iterate in
either ascending or descending order, and the Solution class uses this iterator to find if there are
two elements in the BST that add up to a given target value. */
class BSTIterator {
private:
    stack <TreeNode*> st;
    bool isReverse;

public:
    BSTIterator(TreeNode *root, bool isReverse) {
        this -> isReverse = isReverse;
        pushAll(root);
    }

    int next() {
        TreeNode *topNode = st.top();
        st.pop();
        pushAll(isReverse ? topNode -> left : topNode -> right);
        return topNode -> val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

private:
    void pushAll(TreeNode *node) {
        while(node != NULL) {
            st.push(node);
            if(!isReverse) {
                node = node -> left;
            }
            else {
                node = node -> right;
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;

        BSTIterator it1(root, false);
        BSTIterator it2(root, true);  

        int start = it1.next(), end = it2.next();

        while(start < end) {
            int sum = start + end;
            if(start + end < k) {
                start = it1.next();
            }
            else if(start + end > k) {
                end = it2.next();
            }
            else {
                return true;
            }
        }

        return false;
    }
};