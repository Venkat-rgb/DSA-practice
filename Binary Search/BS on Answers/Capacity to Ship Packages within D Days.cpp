class Solution {
public:
    int check(vector <int> weights, int mid, int days) {
        int days_cnt = 1, weight_left = mid;

        for(int i = 0; i < weights.size(); ++i) {
            if(weight_left >= weights[i]) {
                weight_left -= weights[i];
            }
            else {
                days_cnt++;
                
                if(days_cnt > days) {
                    return 0;
                }

                weight_left = mid;
                
                if(weight_left >= weights[i]) {
                    weight_left -= weights[i];
                }
                else {
                    return 0;
                }
            }
        }

        return days_cnt <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size(), maxi = 0;

        for(int i = 0; i < n; ++i) {
            maxi += weights[i];
        }

        int start = 1, end = maxi, ans = -1;

        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(check(weights, mid, days) == 1) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return ans;
    }
};