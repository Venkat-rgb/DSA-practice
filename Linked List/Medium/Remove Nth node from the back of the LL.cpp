int length(ListNode *head) {
    int len = 0;
    while(head != NULL) {
        head = head -> next;
        len++;
    }
    return len;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == NULL || head -> next == NULL) {
        return NULL;
    }

    int len = length(head) - 1;

    // Deleting starting node
    if(len + 1 == n) {
        head = head -> next;
        return head;
    }

    // Deleting node when n < length of LL
    ListNode *temp = head;
    while(n < len && temp != NULL) {
        len--;
        temp = temp -> next;
    }

    temp -> next = temp -> next -> next;
    return head;
}