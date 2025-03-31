class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();
            stack<pair<int, int>> st;
            vector<int> left(n, -1), right(n, n);
    
            st.push({-1, n});
    
            for (int i = n - 1; i >= 0; --i) {
                while (!st.empty() && st.top().first >= heights[i]) {
                    st.pop();
                }
                right[i] = st.top().second;
                st.push({heights[i], i});
            }
    
            while (!st.empty()) {
                st.pop();
            }
    
            st.push({-1, -1});
    
            for (int i = 0; i < n; ++i) {
                while (!st.empty() && st.top().first >= heights[i]) {
                    st.pop();
                }
                left[i] = st.top().second;
                st.push({heights[i], i});
            }
    
            int maxi = INT_MIN;
    
            for (int i = 0; i < n; ++i) {
                int distance = right[i] - left[i] - 1;
                int maxArea = heights[i] * distance;
                maxi = max(maxi, maxArea);
            }
    
            return maxi;
        }
    };