#include <unordered_set>

vector < int > sortedArray(vector < int > a, vector < int > b) {
    int i = 0, j = 0;

    vector <int> res;

    while(i < a.size() && j < b.size()) {
        if(a[i] == b[j]) {
            if(res.size() == 0 || res.back() != a[i]) {
                res.push_back(a[i]);
            }
            i++;
            j++;
        }
        else if(a[i] < b[j]) {
            if(res.size() == 0 || res.back() != a[i]) {
                res.push_back(a[i]);
            }
            i++;
        }
        else {
            if(res.size() == 0 || res.back() != b[j]) {
                res.push_back(b[j]);
            }
            j++;
        }
    }

    while(i < a.size()) {
        if(res.size() == 0 || res.back() != a[i]) {
            res.push_back(a[i]);    
        }
        i++;
    }

    while(j < b.size()) {
        if(res.size() == 0 || res.back() != b[j]) {
            res.push_back(b[j]);
        }
        j++;
    }

    return res;
}