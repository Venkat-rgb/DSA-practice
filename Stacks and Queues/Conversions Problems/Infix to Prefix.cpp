string infixToPostfix(string& s) {
    string res = "";
    stack <char> st;
    
    int n = s.size();
    
    for(int i = 0; i < n / 2; ++i) {
        if(s[i] == '(') {
            s[i] = ')';
        }
        else if(s[i] == ')') {
            s[i] = '(';
        }
        else if(s[n - i - 1] == '(') {
            s[n - i - 1] = ')';
        }
        else if(s[n - i - 1] == ')') {
            s[n - i - 1] = '(';
        }
        swap(s[i], s[n - i - 1]);
    }
    
    for(int i = 0; i < n; ++i) {
        if((s[i] >= 'a' && s[i] <= 'z') || 
           (s[i] >= 'A' && s[i] <= 'Z') || 
           (s[i] >= '0' && s[i] <= '9')) {
           res += s[i]; 
        }
        else if(s[i] == '(' || (!st.empty() && priority(s[i]) >= priority(st.top()))) {
            st.push(s[i]);
        }
        else if(s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            if(s[i] == '^') {
                while(!st.empty() && priority(s[i]) <= priority(st.top())) {
                    res += st.top();
                    st.pop();
                }
            }
            else {
                while(!st.empty() && priority(s[i]) < priority(st.top())) {
                    res += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()) {
        res += st.top();
        st.pop();
    }

    int size = res.size();
    
    for(int i = 0; i < size / 2; ++i) {
        swap(res[i], res[size - i - 1]);
    }
    
    return res;
}