// 1752. Check if Array Is Sorted and Rotated (Leetcode)
#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int>& nums) {
    int n = nums.size(), cnt = 0;
    for(int i = 1; i < n; ++i) {
        if(nums[i - 1] > nums[i]) {
            cnt++;
        }
    }

    if(nums[0] < nums[n - 1]) {
        cnt++;
    }

    return cnt <= 1;
}

int main() {
    int n;
    cin >> n;
    vector <int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << (check(nums) ? "true" : "false") << endl;
}