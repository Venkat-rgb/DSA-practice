/**
 * The function merges two binary search trees into a single sorted vector.
 * 
 * @param root1 The function `merge` takes two binary search trees represented by their root nodes
 * `root1` and `root2`, and merges them into a single sorted vector of integers. The function uses two
 * stacks `st1` and `st2` to perform an iterative inorder traversal of the two trees simultaneously
 * @param root2 It seems like the code you provided is attempting to merge two binary search trees
 * represented by the root nodes `root1` and `root2`. The function `merge` uses two stacks `st1` and
 * `st2` to perform an iterative inorder traversal on the two trees and merge them into
 * 
 * @return The function `merge` returns a vector of integers that contains the merged elements of two
 * binary search trees represented by the input root nodes `root1` and `root2`.
 */
vector<int> merge(Node *root1, Node *root2) {
    stack <Node*> st1, st2;
    vector <int> res;
    Node *curr1 = root1, *curr2 = root2;
    
    while((curr1 != NULL || !st1.empty()) || (curr2 != NULL || !st2.empty())) {
        while(curr1 != NULL) {
            st1.push(curr1);
            curr1 = curr1 -> left;
        }
        
        while(curr2 != NULL) {
            st2.push(curr2);
            curr2 = curr2 -> left;
        }
        
        if(st2.empty() || (!st1.empty() && st1.top() -> data <= st2.top() -> data)) {
            Node *topNode = st1.top();
            st1.pop();
            res.push_back(topNode -> data);
            curr1 = topNode -> right;
        }
        else if(st1.empty() || (!st2.empty() && st1.top() -> data > st2.top() -> data)) {
            Node *topNode = st2.top();
            st2.pop();
            res.push_back(topNode -> data);
            curr2 = topNode -> right;
        }
    }
    
    return res;
}