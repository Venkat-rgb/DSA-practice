class Solution {
    public:
        ListNode* reverseLL(ListNode* head) {
            if (head == NULL || head->next == NULL) {
                return head;
            }
    
            ListNode *prev = NULL, *curr = head;
    
            while (curr != NULL) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
    
            return prev;
        }
    
        ListNode* reverseKGroup(ListNode* head, int k) {
            if (head == NULL || head->next == NULL || k == 1) {
                return head;
            }
    
            ListNode* temp = head;
            int idx = 1;
    
            while (idx < k && temp != NULL) {
                temp = temp->next;
                idx++;
            }
    
            if (temp != NULL) {
                ListNode* res = reverseKGroup(temp->next, k);
                temp->next = NULL;
                ListNode* rev = reverseLL(head);
                head->next = res;
                head = rev;
            }
            return head;
        }
    };