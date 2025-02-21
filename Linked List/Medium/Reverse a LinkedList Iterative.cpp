ListNode* reverseList(ListNode* head) {
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    ListNode *prev = NULL, *curr = head;

    while(curr != NULL) {
        ListNode *nextNode = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}