void prePostInorderTraversal(BinaryTree <int> *root) {
    if(root == NULL) return;
    
    vector <int> pre, post, inorder;
    stack <pair<BinaryTree<int>*, int>> st;
    st.push({root, 1});
    
    while(!st.empty()) {
        BinaryTree <int> *topNode = st.top().first;
        int num = st.top().second;
        st.pop();
        
        if(num == 1) {
            pre.push_back(topNode -> data);
            num++;
            st.push({topNode, num});
            
            if(topNode -> left != NULL) {
                st.push({topNode -> left, 1});
            }
        }
        else if(num == 2) {
            inorder.push_back(topNode -> data);
            num++;
            st.push({topNode, num});
            
            if(topNode -> right != NULL) {
                st.push({topNode -> right, 1});
            }
        }
        else if(num == 3) {
            post.push_back(topNode -> data);
        }
    }
    
    for(auto i : pre) {
        cout << i << " ";
    }
    cout << endl;
    
    
    for(auto i : inorder) {
        cout << i << " ";
    }
    cout << endl;
    
    
    for(auto i : post) {
        cout << i << " ";
    }
    cout << endl;
}