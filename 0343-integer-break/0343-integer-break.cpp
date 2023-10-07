class Solution {
public:
    int dp[59][3];
    int helper(int n, int cnt) {
        if(n == 0) {
            if(cnt == 2) return 1;
            return 0;
        }
        
        if(dp[n][cnt] != -1) return dp[n][cnt];
        
        int mx = -1e9;
        for(int i = 1; i <= n; ++i) {
            if(i <= n) {
                mx = max(mx, i * helper(n - i, min(cnt + 1, 2)));
            }
        }
        return dp[n][cnt] = mx;
    }
    int integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(n, 0);
    }
};