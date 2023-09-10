class Solution {
public:
    int mod = 1e9 + 7;
    int dp[3001][1001];
    int helper(int startPos, int endPos, int k) {
        if(k == 0) {
            if(startPos == endPos) return 1;
            return 0;
        }
        
        if(dp[startPos + 1000][k] != -1) return dp[startPos + 1000][k];
        
        int cnt = 0;
        cnt = (cnt + helper(startPos - 1, endPos, k - 1)) % mod;
        cnt = (cnt + helper(startPos + 1, endPos, k - 1)) % mod;
        return dp[startPos + 1000][k] = cnt;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp, -1, sizeof(dp));
        return helper(startPos, endPos, k);
    }
};