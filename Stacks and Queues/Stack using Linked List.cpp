class Stack {
    int currSize;
    Node *tail;

   public:
    Stack() {
        tail = NULL;
        currSize = 0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return currSize;
    }

    bool isEmpty() {
        return currSize == 0;
    }

    void push(int element) {
        Node *newNode = new Node(element);
        if(tail == NULL) {
            tail = newNode;
        }
        else {
            newNode -> next = tail;
            tail = newNode;
        }
        currSize++;
    }

    int pop() {
       if(tail == NULL) {
            return -1;
        }
        int tailData = tail -> data;
        Node *tailNext = tail -> next;
        delete tail;
        tail = tailNext;
        currSize--;
        return tailData;
    }

    int top() {
        if(tail == NULL) {
            return -1;
        }
        return tail -> data;
    }
};