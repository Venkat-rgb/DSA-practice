class Solution {
    public:
        vector<int> NSL(vector<int>& arr) {
            int n = arr.size();
            stack<pair<int, int>> st;
            vector<int> res(n, INT_MIN);
    
            st.push({INT_MIN, -1});
    
            for (int i = 0; i < n; ++i) {
                while (!st.empty() && st.top().first > arr[i]) {
                    st.pop();
                }
                res[i] = i - st.top().second;
                st.push({arr[i], i});
            }
    
            return res;
        }
    
        vector<int> NSR(vector<int>& arr) {
            int n = arr.size();
            stack<pair<int, int>> st;
            vector<int> res(n, INT_MIN);
    
            st.push({INT_MIN, n});
    
            for (int i = n - 1; i >= 0; --i) {
                while (!st.empty() && st.top().first >= arr[i]) {
                    st.pop();
                }
                res[i] = st.top().second - i;
                st.push({arr[i], i});
            }
    
            return res;
        }
    
        vector<int> NGL(vector<int>& arr) {
            int n = arr.size();
            stack<pair<int, int>> st;
            vector<int> res(n, INT_MAX);
    
            st.push({INT_MAX, -1});
    
            for (int i = 0; i < n; ++i) {
                while (!st.empty() && st.top().first < arr[i]) {
                    st.pop();
                }
                res[i] = i - st.top().second;
                st.push({arr[i], i});
            }
    
            return res;
        }
    
        vector<int> NGR(vector<int>& arr) {
            int n = arr.size();
            stack<pair<int, int>> st;
            vector<int> res(n, INT_MAX);
    
            st.push({INT_MAX, n});
    
            for (int i = n - 1; i >= 0; --i) {
                while (!st.empty() && st.top().first <= arr[i]) {
                    st.pop();
                }
                res[i] = st.top().second - i;
                st.push({arr[i], i});
            }
    
            return res;
        }
    
        long long subArrayMinimums(vector<int>& nums) {
            vector<int> left = NSL(nums);
            vector<int> right = NSR(nums);
    
            long long sum = 0;
    
            for (int i = 0; i < nums.size(); ++i) {
                long long numOfSubarraysTimesEl =
                    (left[i] * right[i] * 1LL * nums[i]);
                sum = sum + numOfSubarraysTimesEl;
            }
    
            return sum;
        }
    
        long long subArrayMaximums(vector<int>& nums) {
            vector<int> left = NGL(nums);
            vector<int> right = NGR(nums);
    
            long long sum = 0;
    
            for (int i = 0; i < nums.size(); ++i) {
                long long numOfSubarraysTimesEl =
                    (left[i] * right[i] * 1LL * nums[i]);
                sum = sum + numOfSubarraysTimesEl;
            }
    
            return sum;
        }
    
        long long subArrayRanges(vector<int>& nums) {
            long long maximums = subArrayMaximums(nums);
            long long minimums = subArrayMinimums(nums);
            return maximums - minimums;
        }
    };