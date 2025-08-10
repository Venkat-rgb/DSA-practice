/* The class `Solution` contains functions to merge two Binary Search Trees (BSTs) into a single sorted
list of node values. */
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void sortedBST(Node *root, vector <int> &res) {
        if(root == NULL) return;
        
        sortedBST(root -> left, res);
        res.push_back(root -> data);
        sortedBST(root -> right, res);
    }
    
    vector<int> merge(Node *root1, Node *root2) {
        vector <int> res1, res2;
        vector <int> res;
        
        sortedBST(root1, res1);
        sortedBST(root2, res2);
        
        int i = 0, j = 0;
        
        while(i < res1.size() && j < res2.size()) {
            if(res1[i] <= res2[j]) {
                res.push_back(res1[i++]);
            }
            else {
                res.push_back(res2[j++]);
            }
        }
        
        while(i < res1.size()) {
            res.push_back(res1[i++]);
        }
        
        while(j < res2.size()) {
            res.push_back(res2[j++]);
        }
        
        return res;
    }
};