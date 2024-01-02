class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        int t2 = 1, t3 = 1, t5 = 1;
        for(int i = 2; i <= n; ++i) {
            int val1 = dp[t2] * 2, val2 = dp[t3] * 3, val3 = dp[t5] * 5;
            int minVal = min({val1, val2, val3});
            dp[i] = minVal;
            if(val1 == minVal) t2++;
            if(val2 == minVal) t3++;
            if(val3 == minVal) t5++;
        }
        return dp[n];
    }
};