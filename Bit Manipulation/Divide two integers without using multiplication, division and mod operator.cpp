int divide(int dividend, int divisor) {
    if(dividend == divisor) {
        return 1;
    }

    bool isNegative = false;

    if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
        isNegative = true;
    }

    long long n = abs((long)dividend);
    long long d = abs((long)divisor);
    long long quotient = 0;

    while(n >= d) {
        int cnt = 0;

        while((d << cnt) <= n) {
            cnt++;
        }

        quotient += (1 << cnt - 1);
        n -= (d << cnt - 1);
    }

    if(quotient == (1 << 31) && !isNegative) {
        return INT_MAX;
    }

    if(quotient == (1 << 31) && isNegative) {
        return INT_MIN;
    }

    return isNegative ? -quotient : quotient;
}