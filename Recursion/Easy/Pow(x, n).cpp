class Solution {
public:
    double power(double x, long long n) {
        if(n == 0) {
            return 1;
        }

        double res = power(x, n - 1);

        return (double)res * (double)x;
    }

    double myPow(double x, int n) {
        long long N = n;
        double res;

        if(N < 0) {
            res = power(x, N * -1);
            return (double)1 / (double)res;
        }
        else {
            res = power(x, N);
            return res;
        }

        return res;
    }
};