class MyQueue {
    stack <int> s1, s2;

public:
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(!s2.empty()) {
            int data = s2.top();
            s2.pop();
            return data;
        }

        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        int data = s2.top();
        s2.pop();
        return data;
    }
    
    int peek() {
        if(!s2.empty()) {
            return s2.top();
        }

        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
