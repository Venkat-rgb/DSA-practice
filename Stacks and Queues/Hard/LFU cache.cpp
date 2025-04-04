class Node {
    public:
        int key, value, cnt;
        Node *prev, *next;
    
        Node(int key, int value) {
            this -> key = key;
            this -> value = value;
            cnt = 1;
        }
    };
    
    class List {
    public:
        int size;
        Node *head, *tail;
    
        List() {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head -> next = tail;
            tail -> prev = head;
            size = 0;
        }
    
        void insertAtHead(Node *curr) {
            Node *nextHead = head -> next;
            head -> next = curr;
            curr -> prev = head;
            curr -> next = nextHead;
            nextHead -> prev = curr;
            size++;
        }
    
        void removeNode(Node *curr) {
            curr -> prev -> next = curr -> next;
            curr -> next -> prev = curr -> prev;
            size--;
        }
    };
    
    class LFUCache {
        int capacity, minFreq, currSize;
        unordered_map <int, Node*> keyNode;
        unordered_map <int, List*> freqMap;
    
    public:
        LFUCache(int capacity) {
            this -> capacity = capacity;
            minFreq = 0;
            currSize = 0;
        }
        
        void updateFreqMap(Node *node) {
            keyNode.erase(node -> key);
            freqMap[node -> cnt] -> removeNode(node);
    
            if(node -> cnt == minFreq && freqMap[node -> cnt] -> size == 0) {
                minFreq++;
            }
    
            List *newList = new List();
            if(freqMap.find(node -> cnt + 1) != freqMap.end()) {
                newList = freqMap[node -> cnt + 1];
            }
            node -> cnt += 1;
            newList -> insertAtHead(node);
            freqMap[node -> cnt] = newList;
            keyNode[node -> key] = node;
        }
    
        void put(int key, int value) {
            // Return if given capacity is 0
            if(capacity == 0) {
                return;
            }
    
            // Check if the node exists
            if(keyNode.find(key) != keyNode.end()) {
                Node *curr = keyNode[key];
                curr -> value = value;
                updateFreqMap(curr);
            }
            else {
                // Checking if capacity is full
                if(capacity == currSize) {
                    List *currList = freqMap[minFreq]; 
                    keyNode.erase(currList -> tail -> prev -> key);
                    currList -> removeNode(currList -> tail -> prev);
                    currSize--;
                }
    
                minFreq = 1;
                Node *newNode = new Node(key, value);
                List *newList = new List();
    
                if(freqMap.find(minFreq) != freqMap.end()) {
                    newList = freqMap[minFreq];
                }
    
                newList -> insertAtHead(newNode);
                freqMap[minFreq] = newList;
                keyNode[key] = newNode;
                currSize++;
            }
        }
    
        int get(int key) {
            // If key exists in keyNode
            if(keyNode.find(key) != keyNode.end()) {
                Node *curr = keyNode[key];
                int res = curr -> value;
                updateFreqMap(curr);
                return res;
            }
    
            // If key not exists
            return -1;
        }
    };
    
    /**
     * Your LFUCache object will be instantiated and called as such:
     * LFUCache* obj = new LFUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */