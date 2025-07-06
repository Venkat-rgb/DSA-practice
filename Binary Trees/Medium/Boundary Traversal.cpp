/**
 * The given C++ code defines a function to perform boundary traversal of a binary tree and return the
 * boundary nodes in a vector.
 * 
 * @param root The code you provided is for performing boundary traversal of a binary tree. The
 * `boundaryTraversal` function takes the root of the binary tree as input and returns a vector
 * containing the boundary elements of the tree in a counterclockwise order.
 * @param res The `res` parameter is a reference to a vector of integers. This vector is used to store
 * the boundary elements of a binary tree during the boundary traversal process. The boundary elements
 * include the left boundary nodes, leaf nodes, and right boundary nodes of the binary tree. The
 * `boundaryTraversal` function
 */
void leftBoundary(Node *root, vector <int> &res)  {
        Node *curr = root -> left;
        
        while(curr != NULL) {
            if(curr -> left != NULL || curr -> right != NULL) {
                res.push_back(curr -> data);
            }
            
            if(curr -> left != NULL) {
                curr = curr -> left;
            }
            else {
                curr = curr -> right;
            }
        }
    }
    
    void leafNodes(Node *root, vector <int> &res)  {
        if(root == NULL) return;
        
        if(root -> left == NULL && root -> right == NULL) {
            res.push_back(root -> data);
            return;
        }
        
        leafNodes(root -> left, res);
        leafNodes(root -> right, res);
    }
    
    void rightBoundary(Node *root, vector <int> &res)  {
        Node *curr = root -> right;
        
        stack <int> st;
        
        while(curr != NULL) {
            if(curr -> left != NULL || curr -> right != NULL) {
                st.push(curr -> data);
            }
            
            if(curr -> right != NULL) {
                curr = curr -> right;
            }
            else {
                curr = curr -> left;
            }
        }
        
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
    }
  
    vector<int> boundaryTraversal(Node *root) {
        vector <int> res;
        if(root == NULL) return res;
        
        res.push_back(root -> data);
        
        if(root -> left == NULL && root -> right == NULL) return res;
        
        leftBoundary(root, res);
        leafNodes(root, res);
        rightBoundary(root, res);
        
        return res;
    }