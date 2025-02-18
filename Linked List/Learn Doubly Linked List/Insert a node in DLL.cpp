class Solution {
    public:
      // Function to insert a new node at given position in doubly linked list.
      Node *addNode(Node *head, int pos, int data) {
          if(head == NULL) {
              return head;
          }
          
          Node *newNode = new Node(data);
          int posi = pos + 1;
          
          int idx = 0;
          Node *temp = head;
          
          while(idx < posi - 1 && temp != NULL) {
              temp = temp -> next;
              idx++;
          }
          
          if(temp != NULL) {
              Node *nextNode = temp -> next;
              temp -> next = newNode;
              newNode -> prev = temp;
              newNode -> next = nextNode;
              if(nextNode != NULL) {
                  nextNode -> prev = newNode;        
              }   
          }
          
          return head;
      }
  };