#include <unordered_map>

long long pairsWithGivenSum(int arr[], int n, int sum)
{
    unordered_map <int, int> mp;
 
    long long cnt = 0;

    for(int i = 0; i < n; ++i) {
        long long diff = sum - arr[i];
        if(mp.find(diff) != mp.end()) {
            cnt += mp[diff];
        }

        mp[arr[i]]++;
    }

    return cnt;
}