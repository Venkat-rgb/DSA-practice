class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            stack <int> st;
            vector <int> res;
    
            for(int i = nums.size() - 1; i >= 0; --i) {
                st.push(nums[i]);
            }
    
            for(int i = nums.size() - 1; i >= 0; --i) {
                while(!st.empty() && st.top() <= nums[i]) {
                    st.pop();
                }
                res.push_back(st.empty() ? -1 : st.top());
                st.push(nums[i]);
            }
    
            for(int i = 0; i < res.size() / 2; ++i) {
                swap(res[i], res[res.size() - i - 1]);
            }
    
            return res;
        }
    };