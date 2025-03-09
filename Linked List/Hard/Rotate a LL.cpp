class Solution {
    public:
        int length(ListNode* head) {
            int len = 0;
            while (head != NULL) {
                head = head->next;
                len++;
            }
            return len;
        }
    
        ListNode* rotateRight(ListNode* head, int k) {
            if(head == NULL || head -> next == NULL) {
                return head;
            }
    
            int len = length(head);
            int idx = 1, pos = (k % len), kth = len - pos;
            ListNode* temp = head;
    
            if (pos == 0) {
                return head;
            }
    
            while (idx < kth && temp != NULL) {
                temp = temp->next;
                idx++;
            }
    
            ListNode *nextNode = temp->next, *newHead = nextNode;
            temp->next = NULL;
    
            while (nextNode->next != NULL) {
                nextNode = nextNode->next;
            }
    
            nextNode->next = head;
    
            return newHead;
        }
    };