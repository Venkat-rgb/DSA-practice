class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;

        long long i;

        for(i = 2; i * i <= n; ++i) {
            if(n % i == 0) {
                if((i == 2) || (i == 3) || (i == 5)) {
                    while(n % i == 0) {
                        n /= i;
                    }
                }
                else {
                    return false;
                }
            }
        }

        if(n != 1) {
            if((n != 2) && (n != 3) && (n != 5)) {
                return false;
            }
        }

        return true;
    }
};