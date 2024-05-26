class Solution {
public:
    int mod = 1e9 + 7;
    int dp[100001][2][3];
    int helper(int n, bool prevAbsent, int lateCnt) {
        if(n == 0) {
            return 1;
        }
        
        if(dp[n][prevAbsent][lateCnt] != -1) return dp[n][prevAbsent][lateCnt];
        
        int ways = 0;
        ways = (ways + helper(n - 1, prevAbsent, 2)) % mod;
        if(lateCnt > 0) ways = (ways + helper(n - 1, prevAbsent, lateCnt - 1)) % mod;
        if(!prevAbsent) ways = (ways + helper(n - 1, true, 2)) % mod;
        return dp[n][prevAbsent][lateCnt] = ways;
    }
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(n, false, 2);
    }
};