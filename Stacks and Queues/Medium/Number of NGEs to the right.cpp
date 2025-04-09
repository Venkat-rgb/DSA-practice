//User function Template for C++
// Time comlpexity: O(N * queries)
class Solution{
    public:
    
        vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
            vector <int> res;
            
            for(int i = 0; i < queries; ++i) {
                int cnt = 0;
                for(int j = indices[i] + 1; j < n; ++j) {
                    if(arr[j] > arr[indices[i]]) {
                        cnt++;
                    }
                }
                res.push_back(cnt);
            }
            
            return res;
        }
    
    };