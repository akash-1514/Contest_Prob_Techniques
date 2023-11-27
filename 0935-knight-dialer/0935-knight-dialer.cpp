class Solution {
private:
    int mod = 1e9 + 7;
    vector<vector<int>> nextPos = {
        {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};
public:
    int dp[5001][10];
    int helper(int n, int nxt) {
        if(n == 1) {
            return 1;
        }
        
        if(dp[n][nxt] != -1) return dp[n][nxt];
        
        int cnt = 0;
        
        for(int nPos : nextPos[nxt]) {
            cnt = (cnt + helper(n - 1, nPos)) % mod;
        }
        
        return dp[n][nxt] = cnt;
    }
    int knightDialer(int n) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int i = 0; i < 10; ++i) {
            ans = (ans + helper(n, i)) % mod;
        }
        return ans;
    }
};