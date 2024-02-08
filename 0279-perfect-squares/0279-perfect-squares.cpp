class Solution {
public:
    int dp[10001];
    int helper(int n) {
        if(n == 0) {
            return 0;
        }
        
        if(dp[n] != -1) return dp[n];
        
        int mn = 1e9;
        for(int i = 1; i * i <= n; ++i) {
            mn = min(mn, 1 + helper(n - i * i));
        }
        return dp[n] = mn;
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(n);
    }
};