bool isSubsequence(int start, int end, string s, string t) {    
    int idx = 0;
    
    while(idx < t.size() && start <= end) {
        if(s[start] == t[idx]) {
            start++;
            idx++;
        }
        else {
            start++;
        }
    }
    
    return idx == t.size();
}

string minWindow(string s, string t)
{
	int m = s.size(), n = t.size();
    int i = 0, j = 0;
    string res = "";

    if (n > m) {
        return res;
    }

    unordered_map<char, int> mp;

    for (int i = 0; i < n; ++i) {
        mp[t[i]]++;
    }

    int cnt = mp.size(), mini = INT_MAX, start = -1, end = -1;

    while (j < m) {
        if (mp.find(s[j]) != mp.end()) {
            mp[s[j]]--;
            if (mp[s[j]] == 0) {
                cnt--;
            }
        }

        while (cnt == 0) {
            bool isSubs = isSubsequence(i, j, s, t);
            
            if(isSubs) {
                if (mini > j - i + 1) {
                    mini = j - i + 1;
                    start = i;
                    end = j;
                }

                if (mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if (mp[s[i]] == 1) {
                        cnt++;
                    }
                }

                i++;
            }
            else {
                break;
            }
        }

        j++;
    }

    if (start != -1) {
        for (int i = start; i <= end; ++i) {
            res += s[i];
        }
    }

    return res;
}