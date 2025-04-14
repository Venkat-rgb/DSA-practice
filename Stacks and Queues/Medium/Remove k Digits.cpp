// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
    public:
        string removeKdigits(string num, int k) {
            int n = num.size();
            stack<char> st;
    
            if (n == k) {
                return "0";
            }
    
            for (int i = 0; i < n; ++i) {
                // If stack is empty, then pushing element to stack
                // If k == 0, then also we directly push element to stack
                if (st.empty() || k == 0) {
                    st.push(num[i]);
                } else {
    
                    // Deleting the larger elements and decrementing k till we find
                    // the smaller element
                    while (!st.empty() && st.top() > num[i] && k > 0) {
                        st.pop();
                        k--;
                    }
    
                    // After deleting the larger elements from stack, pushing the
                    // smaller element
                    st.push(num[i]);
                }
            }
    
            // There can be case where k > 0, like num = "12345", stack =
            // [1,2,3,4,5] So K can be anywhere from 1 till unchanged So in this
            // case we need to delete these k elements from stack
            while (!st.empty() && k > 0) {
                st.pop();
                k--;
            }
    
            // There can be case where after deleting the k elements stack can be
            // empty, if yes then return 0
            if (st.empty()) {
                return "0";
            }
    
            string res = "";
    
            // Storing the answer in res using the stack
            while (!st.empty()) {
                res += st.top();
                st.pop();
            }
    
            // There can be case where res can contain leading zeros, so we remove
            // them
            while (res.size() > 0 && res.back() == '0') {
                res.pop_back();
            }
    
            // There can be case where all elements from res are deleted when if res
            // contained all zeros like this "0000"
            if (res.empty()) {
                return "0";
            }
    
            // Reversing the result as stack stores in reverse order
            reverse(res.begin(), res.end());
    
            return res;
        }
    };