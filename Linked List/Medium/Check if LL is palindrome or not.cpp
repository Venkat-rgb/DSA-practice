ListNode* midPoint(ListNode* head) {
    ListNode *slow = head, *fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* reverseLL(ListNode* head) {
    ListNode *curr = head, *prev = NULL;

    while (curr != NULL) {
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

bool isPalindrome(ListNode* head) {
    if(head == NULL || head -> next == NULL) {
        return true;
    }

    ListNode *mid = midPoint(head);
    ListNode *rev = reverseLL(mid -> next);
    mid -> next = NULL;

    while(head != NULL && rev != NULL) {
        if(head -> val != rev -> val) {
            return false;
        }
        head = head -> next;
        rev = rev -> next;
    }

    return true;
}