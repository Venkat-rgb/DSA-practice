class Solution {
    public:
      Node *reverseLL(Node *head) {
          if(head == NULL || head -> next == NULL) {
              return head;
          }
          
          Node *prev = NULL, *curr = head;
          
          while(curr != NULL) {
              Node *nextNode = curr -> next;
              curr -> next = prev;
              prev = curr;
              curr = nextNode;
          }
          
          return prev;
      }
    
      Node* addOne(Node* head) {
          bool isLastDigitNine = false;
          Node *revRes = reverseLL(head);
          Node *temp = revRes;
      
          while(temp != NULL) {
              if(temp -> data == 9) {
                  temp -> data = 0;
                  if(temp -> next == NULL) {
                      isLastDigitNine = true;
                      break;
                  }
              }
              else {
                  break;
              }
              temp = temp -> next;
          }
          
          if(isLastDigitNine) {
              Node *newNode = new Node(1);
              temp -> next = newNode;
          }
          else {
              temp -> data++;
          }
      
          Node *res = reverseLL(revRes);
          return res;
      }
  };