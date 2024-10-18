int check(vector <int> arr, int mid, int x) {
	if(arr[mid] > x) {
		return 1;
	}
	
	return 0;
}

int lowerBound(vector<int> arr, int n, int x) {
	int start = 0, end = n - 1, ans = n;

	while(start <= end) {
		int mid = start + (end - start) / 2;
		if(check(arr, mid, x) == 1) {
			ans = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	return ans;
}
