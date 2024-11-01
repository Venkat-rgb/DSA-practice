class Solution {
public:
    int check(vector <int> bloomDay, int mid, int m, int k) {
        int bouquets_made = 0, adjacent_cnt = 0;

        for(int i = 0; i < bloomDay.size(); ++i) {
            if(bloomDay[i] <= mid) {
                adjacent_cnt++;
                if(adjacent_cnt == k) {
                    bouquets_made++;
                    adjacent_cnt = 0;
                }
            }
            else {
                adjacent_cnt = 0;
            }
        }

        return bouquets_made >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(), mini = INT_MAX, maxi = INT_MIN;

        if((long long)m * k > n) {
            return -1;
        }

        for(int i = 0; i < n; ++i) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int start = mini, end = maxi, ans = -1;

        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(check(bloomDay, mid, m, k) == 1) {
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