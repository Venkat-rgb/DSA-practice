// User function Template for C++

class Solution {
    public:
      string postToPre(string post_exp) {
          stack <string> st;
      
          for(int i = 0; i < post_exp.size(); ++i) {
              if(isalnum(post_exp[i])) {
                  st.push(string(1, post_exp[i]));
              }
              else {
                  if(st.size() >= 2) {
                      string s1 = st.top();
                      st.pop();
                      string s2 = st.top();
                      st.pop();
                      
                      string res = post_exp[i] + s2 + s1;
                      st.push(res);
                  }
              }
          }
          
          return st.top();
      }
  };