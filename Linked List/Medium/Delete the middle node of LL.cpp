ListNode* deleteMiddle(ListNode* head) {
    if (head == NULL || head -> next == NULL) {
        return NULL;
    }

    ListNode *slow = head, *fast = head, *prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    
    prev -> next = prev -> next -> next;
    return head;
}