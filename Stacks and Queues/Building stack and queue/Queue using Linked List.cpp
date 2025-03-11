class Queue {
	int currSize;
	Node *head, *tail;
public:
    Queue() {
		head = NULL;
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

    void enqueue(int data) {
		Node *newNode = new Node(data);
		if(head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail -> next = newNode;
			tail = newNode;
		}
		currSize++;
	}

    int dequeue() {
		if(head == NULL) {
			return -1;
		}
		int popNodeData = head -> data;
		Node *temp = head;
		head = head -> next;
		delete temp;
		currSize--;
		return popNodeData;

    }

    int front() {
		if(head == NULL) {
			return -1;
		}
		return head -> data;
    }
};