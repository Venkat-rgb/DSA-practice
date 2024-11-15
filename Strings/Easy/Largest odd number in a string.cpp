class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        
        // If num is already odd
        if((num.back() - '0') % 2 == 1) {
            return num;
        }

        for(int i = n - 1; i >= 0; --i) {
            int singleNum = num[i] - '0';
            if(singleNum % 2 == 1) {
                return num.substr(0, i + 1);
            }
        }
        
        return ""; 
    }
};  