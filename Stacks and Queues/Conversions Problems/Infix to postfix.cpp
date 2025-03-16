class Solution {
    public:
      // Function to convert an infix expression to a postfix expression.
      int priority(char c) {
          if(c == '^') return 3;
          if(c == '*' || c == '/') return 2;
          if(c == '+' || c == '-') return 1;
          return -1;
      }
      
      string infixToPostfix(string& s) {
          string res = "";
          stack <char> st;
          
          for(int i = 0; i < s.size(); ++i) {
              if((s[i] >= 'a' && s[i] <= 'z') || 
                 (s[i] >= 'A' && s[i] <= 'Z') || 
                 (s[i] >= '0' && s[i] <= '9')) {
                 res += s[i]; 
              }
              else if(s[i] == '(' || (!st.empty() && priority(s[i]) > priority(st.top()))) {
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
                  while(!st.empty() && priority(s[i]) <= priority(st.top())) {
                      res += st.top();
                      st.pop();
                  }
                  st.push(s[i]);
              }
          }
          
          while(!st.empty()) {
              res += st.top();
              st.pop();
          }
          
          return res;
      }
  };