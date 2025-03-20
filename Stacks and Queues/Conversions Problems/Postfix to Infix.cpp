// User function Template for C++

class Solution {
    public:
      string postToInfix(string exp) {
          stack <string> st;
          
          for(int i = 0; i < exp.size(); ++i) {
              if(isalnum(exp[i])) {
                  st.push(string(1, exp[i]));
              }
              else {
                  if(st.size() >= 2) {
                      string s1 = st.top();
                      st.pop();
                      string s2 = st.top();
                      st.pop();
                      string res = "(" + s2 + exp[i] + s1 + ")";
                      st.push(res);
                  }
              }
          }
          
          if(!st.empty()) {
              return st.top();
          }
      }
  };