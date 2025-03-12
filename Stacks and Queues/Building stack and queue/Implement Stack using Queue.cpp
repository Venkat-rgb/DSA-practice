class MyStack {
    queue <int> q;
public:
   
    void push(int x) {
        if(q.empty()) {
            q.push(x);
        }
        else {
            int size = q.size();
            q.push(x);

            for(int i = 0; i < size; ++i) {
                int el = q.front();
                q.pop();
                q.push(el);
            }
        }
    }
    
    int pop() {
        if(q.empty()) {
            return -1;
        }
        int data = q.front();
        q.pop();
        return data;
    }
    
    int top() {
        if(q.empty()) {
            return -1;
        }
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

