class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;

        int start = 0, end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            int maxi = 0, maxIdx = -1;

            for (int i = 0; i < m; ++i) {
                if (mat[i][mid] > maxi) {
                    maxi = mat[i][mid];
                    maxIdx = i;
                }
            }

            int left = mid - 1 >= 0 ? mat[maxIdx][mid - 1] : -1;
            int right = mid + 1 < n ? mat[maxIdx][mid + 1] : -1;

            if(mat[maxIdx][mid] > left && mat[maxIdx][mid] > right) {
                return {maxIdx, mid};
            }
            else if(mat[maxIdx][mid] < left) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return res;
    }
};