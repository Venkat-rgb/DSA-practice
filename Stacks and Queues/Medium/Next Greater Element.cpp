// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            int n1 = nums1.size(), n2 = nums2.size();
            unordered_map<int, int> mp;
            stack<int> st;
            vector<int> res;
    
            for (int i = n2 - 1; i >= 0; --i) {
                while (!st.empty() && st.top() <= nums2[i]) {
                    st.pop();
                }
                mp[nums2[i]] = st.empty() ? -1 : st.top();
                st.push(nums2[i]);
            }
    
            for (int i = 0; i < n1; ++i) {
                if (mp.find(nums1[i]) != mp.end()) {
                    res.push_back(mp[nums1[i]]);
                }
            }
    
            return res;
        }
    };