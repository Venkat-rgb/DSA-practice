class Solution {
    public:
        int maximumHistogram(vector <int> arr) {
            int n = arr.size();
            stack <pair<int, int>> st;
            vector <int> left(n, -1), right(n, n);
    
            st.push({-1, -1});
    
            for(int i = 0; i < n; ++i) {
                while(!st.empty() && st.top().first >= arr[i]) {
                    st.pop();
                }
                left[i] = st.top().second;
                st.push({arr[i], i});
            }
    
            while(!st.empty()) {
                st.pop();
            }
    
            st.push({-1, n});
    
            for(int i = n - 1; i >= 0; --i) {
                while(!st.empty() && st.top().first >= arr[i]) {
                    st.pop();
                }
                right[i] = st.top().second;
                st.push({arr[i], i});
            }
    
            int maxArea = INT_MIN;
            for(int i = 0; i < n; ++i) {
                int distance = right[i] - left[i] - 1;
                int area = distance * arr[i];
                maxArea = max(maxArea, area);
            }
    
            return maxArea;
        }
    
        int maximalRectangle(vector<vector<char>>& matrix) {
            int rows = matrix.size(), cols = matrix[0].size();
            vector <int> res(cols, 0);
            int maxRectLen = INT_MIN;
    
            for(int i = 0; i < rows; ++i) {
                for(int j = 0; j < cols; ++j) {
                    if(matrix[i][j] - '0' == 0) {
                        res[j] = 0;
                    }
                    else {
                        res[j] += matrix[i][j] - '0';
                    }
                }
                int maxArea = maximumHistogram(res);
                maxRectLen = max(maxRectLen, maxArea);
            }
    
            return maxRectLen;
        }
    };