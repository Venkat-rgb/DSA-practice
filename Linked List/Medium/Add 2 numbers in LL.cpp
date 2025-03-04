ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *resHead = new ListNode(0);
    ListNode *resTail = resHead;
    int carry = 0;

    while(l1 != NULL || l2 != NULL) {
        int sum1 = l1 ? l1 -> val : 0;
        int sum2 = l2 ? l2 -> val : 0;
        int totalSum = carry + sum1 + sum2;

        carry = totalSum / 10;
        resTail -> next = new ListNode(totalSum % 10);
        resTail = resTail -> next;

        l1 = l1 ? l1 -> next : NULL;
        l2 = l2 ? l2 -> next : NULL;
    } 

    if(carry == 1) {
        ListNode *newNode = new ListNode(1);
        resTail -> next = newNode;
    }

    ListNode *res = resHead -> next;
    delete resHead;
    return res;
}