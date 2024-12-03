class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        long long maxi = 0, leftSum = 0;

        for(int i = 0; i < k; ++i) {
            leftSum += cardPoints[i];
            maxi = max(maxi, leftSum);
        }

        long long rightIdx = n - 1, rightSum = 0;
        
        for(int i = k - 1; i >= 0; --i) {
            leftSum -= cardPoints[i];
            rightSum += cardPoints[rightIdx];
            maxi = max(maxi, leftSum + rightSum);
            rightIdx--;
        }

        return maxi;
    }
};