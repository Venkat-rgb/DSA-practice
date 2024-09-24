#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int idx = 0;
    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] != 0) {
            swap(nums[idx], nums[i]);
            idx++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }   

    moveZeroes(arr);

    for(int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}