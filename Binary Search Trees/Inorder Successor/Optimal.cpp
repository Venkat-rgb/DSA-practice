int inOrderSuccessor(Node *root, Node *x) {
    int successor = -1;
    
    Node *curr = root;
    while(curr != NULL) {
        if(curr -> data > x -> data) {
            successor = curr -> data;
            curr = curr -> left;
        }
        else {
            curr = curr -> right;
        }
    }
    
    return successor;
}