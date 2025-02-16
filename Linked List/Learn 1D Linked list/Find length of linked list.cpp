class Solution {
    public:
      // Function to count nodes of a linked list.
      int getCount(struct Node* head) {
  
          int len = 0;
          while(head != NULL) {
              head = head -> next;
              len++;
          }
          return len;
      }
  };