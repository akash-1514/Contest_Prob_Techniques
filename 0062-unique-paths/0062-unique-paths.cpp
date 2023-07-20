class Solution {
public:
    int dp[101][101];
    int helper(int m, int n) {
        if(m == 0 && n == 0) return 1;
        if(dp[m][n] != -1) return dp[m][n];
        int cnt = 0;
        if(m - 1 >= 0) {
            cnt += helper(m - 1, n);
        }
        if(n - 1 >= 0) {
            cnt += helper(m, n - 1);
        }
        return dp[m][n] = cnt;
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return helper(m - 1, n - 1);
    }
};