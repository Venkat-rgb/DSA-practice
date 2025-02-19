class Solution {
    public:
      // Function to delete a node at given position.
      Node* deleteNode(Node* head, int x) {
          if(head == NULL) {
              return head;
          }
          
          int posi = x - 1;
          
          // Handling pos == 0
          if(posi == 0) {
              head = head -> next;
              head -> prev = NULL;
              return head;
          }
          
          int idx = 0;
          Node *temp = head;
          
          while(idx < posi - 1 && temp != NULL) {
              temp = temp -> next;
              idx++;
          }
          
          if(temp != NULL && temp -> next != NULL) {
              Node *nextNode = temp -> next -> next;
              temp -> next = nextNode;
              if(nextNode != NULL) {
                  nextNode -> prev = temp;            
              }
          }
          
          return head;
      }
  };