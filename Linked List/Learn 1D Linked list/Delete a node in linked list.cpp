Node *deleteNode(Node *head, int pos) {
    Node *temp = head;

    // Handles if linked list is empty
    if(temp == NULL) {
        return temp;
    }

    // Handles deletion at start
    if(pos <= 0) {
        temp = temp -> next;
        delete head;
        return temp;
    }

    int idx = 0;
    while(idx < pos - 1 && temp != NULL) {
        temp = temp -> next;
        idx++;
    }

    // Handles deletion at middle and end
    if(temp != NULL && temp -> next != NULL) {
        Node *a = temp -> next -> next;
        delete temp -> next;
        temp -> next = a;
    }

    return head;
}