class Solution {
    public:
        int trap(vector<int>& height) {
            int n = height.size(), rightMax = INT_MIN, totalTrappedWater = 0;
    
            vector<int> right(n, -1);
    
            for (int i = n - 1; i >= 0; --i) {
                rightMax = max(rightMax, height[i]);
                right[i] = rightMax;
            }
    
            int leftMax = INT_MIN;
    
            for (int i = 0; i < n; ++i) {
                leftMax = max(leftMax, height[i]);
                int mini = min(leftMax, right[i]);
                int currBuildTrappedWater = mini - height[i];
                totalTrappedWater += currBuildTrappedWater;
            }
            
            return totalTrappedWater;
        }
    };