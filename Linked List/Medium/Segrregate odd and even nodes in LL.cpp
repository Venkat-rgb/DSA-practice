ListNode* oddEvenList(ListNode* head) {
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    ListNode *oh = NULL, *ot = NULL, *eh = NULL, *et = NULL, *temp = head;
    int idx = 0;

    while(temp != NULL) {
        if(idx % 2 == 0) {
            if(eh == NULL) {
                eh = temp;
                et = temp;
            }
            else {
                et -> next = temp;
                et = temp;
            }
        }
        else {
            if(oh == NULL) {
                oh = temp;
                ot = temp;
            }
            else {
                ot -> next = temp;
                ot = temp;
            }
        }
        idx++;
        temp = temp -> next;
    }

    et -> next = oh;
    ot -> next = NULL;

    return eh;
}