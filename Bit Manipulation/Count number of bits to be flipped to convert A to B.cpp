int minBitFlips(int start, int goal) {
    int zeros = 0, ones = 0, total = 0;

    for(int i = 0; i < 32; ++i) {
        int LSBofStart = start & (1 << i);
        int LSBofGoal = goal & (1 << i);

        if(LSBofStart == 0) zeros++;
        else ones++;

        if(LSBofGoal == 0) zeros++;
        else ones++;

        total += (zeros * ones);
        zeros = 0;
        ones = 0;
    }

    return total;
}