class Solution {
public:
    int dp[20];
    int helper(int n) {
        if(n == 0) return 1;
        if(n == 1 || n == 2) return n;
        
        if(dp[n] != -1) return dp[n];
        
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            int right = helper(n - i);
            int left = helper(i - 1);
            
            ans += left * right;
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(n);
    }
};