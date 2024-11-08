// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int maxi = 0, maxIdx = -1;
        int n = arr.size(), m = arr[0].size();
        
        for(int i = 0; i < n; ++i) {
            int start = 0, end = m - 1;
            if(arr[i][end] == 0) {
                continue;
            }
            while(start <= end) {
                if(arr[i][start] == 0) {
                    start++;
                }
                else {
                    int res = m - start;
                    if(res > maxi) {
                        maxi = res;
                        maxIdx = i;
                    }
                    break;
                }
            }
        }
        
        return maxIdx;
    }
};