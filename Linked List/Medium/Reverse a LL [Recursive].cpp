ListNode* reverseList(ListNode* head) {
    // 1) Base case
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    // 2) Recursion work
    ListNode *res = reverseList(head -> next);

    // 3) My work
    head -> next -> next = head;
    head -> next = NULL;

    return res;
}