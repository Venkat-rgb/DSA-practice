#include <unordered_map>

int longestSubarrayWithSumK(vector<int> a, long long k) {
    
    unordered_map <int, int> mp;

    long long sum = 0;
    int maxLen = -1;

    for(int i = 0; i < a.size(); ++i) {
        sum += a[i];
        // Handling case where we get direct sum == k in first part
        if(sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        /*
         -> Handling case where we don't get direct sum == k.
         -> So we are checking if sum - k exists in prefix sum till now
         -> If it exists then it means that we got another subarray with sum = k
         -> So we check if this subarray has longest length
        */

        long long rem = sum - k;
        if(mp.find(rem) != mp.end()) {
            maxLen = max(maxLen, i - mp[rem]);
        }

        /*
           -> Handles the case where array contains 0's like this:
           [1,0,0,0,1]
           -> Here maxlength is 4, but we need to make sure we are not updating
           the index of sum.
           -> Bcz if you update the index, then we will lose the maximum length 
        */

        // Updating the index of sum only, if sum doesn't exists in map
        if(mp.find(sum) == mp.end()) {
            // Helps in calculating length of subarray
            mp[sum] = i;
        }
    }

    return maxLen;
}