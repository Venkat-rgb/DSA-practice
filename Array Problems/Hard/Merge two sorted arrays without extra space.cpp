#include<vector>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	int n = a.size(), m = b.size();

	int i = n - 1, j = 0;

	while(i >= 0 && j < m) {
		if(a[i] >= b[j]) {
			swap(a[i], b[j]);
			i--;
			j++;
		}
		else {
			break;
		}
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
}

// Time complexity: O(min(m, n)) + O(MlogM) + O(NlogN)
// Space complexity: O(1)