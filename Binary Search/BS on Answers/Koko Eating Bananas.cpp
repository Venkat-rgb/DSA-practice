class Solution {
public:
    int check(vector <int> piles, long long m, int h) {
        int hours = 0;

        for(int i = 0; i < piles.size(); ++i) {
            if(hours > h) {
                return 0;
            }

            if(m > piles[i]) {
                hours++;
            }
            else {
                hours += ceil(piles[i] / (m + 0.0));
            }
        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int maxi = INT_MIN;
        for(int i = 0; i < n; ++i) {
            maxi = max(maxi, piles[i]);
        }

        long long start = 1, end = maxi, ans = -1;

        while(start <= end) {
            long long mid = start + (end - start) / 2;
            if(check(piles, mid, h) == 1) {
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