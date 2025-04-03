class Node {
    public:
        pair<int, int> data;
        Node *prev, *next;
    
        Node(pair<int, int> data) {
            this->data = data;
            prev = NULL;
            next = NULL;
        }
    };
    
    class LRUCache {
        int capacity;
        Node *head, *tail;
        unordered_map<int, Node*> mp;
    
    public:
        LRUCache(int capacity) {
            this->capacity = capacity;
            head = new Node({-1, -1});
            tail = new Node({-1, -1});
            head->next = tail;
            tail->prev = head;
        }
    
        void insertAtHead(Node *curr) {
            Node* nextHead = head -> next;
            head -> next = curr;
            curr -> prev = head;
            curr -> next = nextHead;
            nextHead -> prev = curr;
        }
    
        void removeNode(Node *curr) {
            curr -> prev -> next = curr -> next;
            curr -> next -> prev = curr -> prev;
        }
        
        void put(int key, int value) {
            if (mp.find(key) == mp.end()) {
                if (mp.size() == capacity) {
                    Node* lastNode = tail->prev;
                    mp.erase(lastNode -> data.first);
                    removeNode(lastNode);
                    delete lastNode;
                } 
                Node* newNode = new Node({key, value});
                insertAtHead(newNode);
                mp[key] = newNode;
            } else {
                Node* curr = mp[key];
                curr->data.second = value;
                removeNode(curr);
                insertAtHead(curr);
            }
        }
    
        int get(int key) {
            if (mp.find(key) == mp.end()) {
                return -1;
            }
    
            Node* curr = mp[key];
            int res = curr -> data.second;
            removeNode(curr);
            insertAtHead(curr);
            return res;
        }
    };