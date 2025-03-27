class Solution {
    public:
        int sumSubarrayMins(vector<int>& arr) {
            int n = arr.size(), mod = (int)(1e9 + 7);
            stack<pair<int, int>> st;
            vector<int> left(n, -1), right(n, n);
    
            // Finding NSL
            st.push({-1, -1});
    
            for (int i = 0; i < n; ++i) {
                while (!st.empty() && st.top().first >= arr[i]) {
                    st.pop();
                }
                left[i] = i - st.top().second;
                st.push({arr[i], i});
            }
    
            // Clearing stack so that we can find NSR
            while (!st.empty()) {
                st.pop();
            }
    
            // Finding NSR
            st.push({-1, n});
    
            for (int i = n - 1; i >= 0; --i) {
                while (!st.empty() && st.top().first > arr[i]) {
                    st.pop();
                }
                right[i] = st.top().second - i;
                st.push({arr[i], i});
            }
    
            // Calculating minimum of each subarray and sum
            int sum = 0;
    
            for (int i = 0; i < n; ++i) {
                int numOfSubarraysTimesEl = (left[i] * right[i] * 1LL * arr[i]) % mod;
                sum = (sum + numOfSubarraysTimesEl) % mod;
            }
    
            return sum % mod;
        }
    };