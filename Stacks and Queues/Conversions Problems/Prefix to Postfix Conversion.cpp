// User function Template for C++

class Solution {
    public:
      string preToPost(string pre_exp) {
          stack <string> st;
          int n = pre_exp.size();
      
          for(int i = n - 1; i >= 0; --i) {
              if(isalnum(pre_exp[i])) {
                  st.push(string(1, pre_exp[i]));
              }
              else {
                  if(st.size() >= 2) {
                      string s1 = st.top();
                      st.pop();
                      string s2 = st.top();
                      st.pop();
                      
                      string res = s1 + s2 + pre_exp[i];
                      st.push(res);
                  }
              }
          }
          
          return st.top();
      }
  };