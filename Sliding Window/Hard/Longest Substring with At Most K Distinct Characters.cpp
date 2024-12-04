#include <unordered_map>

int getLengthofLongestSubstring(int k, string s)
{
   int n = s.size(); 
   unordered_map <char, int> mp;

   int i = 0, j = 0, maxi = 0;

   while(j < n) {
      mp[s[j]]++;

      while(mp.size() > k) {
         mp[s[i]]--;

         if(mp[s[i]] == 0) {
            mp.erase(s[i]);
         }

         i++;
      }

      if(mp.size() <= k) {
         maxi = max(maxi, j - i + 1);
      }

      j++;
   }

   return maxi;
}
