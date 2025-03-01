ListNode* midPoint(ListNode* head) {
    ListNode *slow = head, *fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* merge(ListNode* head1, ListNode* head2) {
    if (head1 == NULL) {
        return head2;
    }

    if (head2 == NULL) {
        return head1;
    }

    ListNode *temp1 = head1, *temp2 = head2, *prev = NULL;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->val < temp2->val) {
            if (prev == NULL) {
                prev = temp1;
            } else {
                prev->next = temp1;
                prev = temp1;
            }
            temp1 = temp1->next;
        } else {
            if (prev == NULL) {
                prev = temp2;
            } else {
                prev->next = temp2;
                prev = temp2;
            }
            temp2 = temp2->next;
        }
    }

    if (temp1 != NULL) {
        prev->next = temp1;
    }

    if (temp2 != NULL) {
        prev->next = temp2;
    }

    return head1->val < head2->val ? head1 : head2;
}

ListNode* sortList(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* mid = midPoint(head);
    ListNode* midNext = mid->next;
    mid->next = NULL;

    ListNode* head1 = sortList(head);
    ListNode* head2 = sortList(midNext);

    ListNode* res = merge(head1, head2);
    return res;
}