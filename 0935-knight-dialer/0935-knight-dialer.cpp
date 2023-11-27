class Solution {
private:
    int mod = 1e9 + 7;
    vector<vector<int>> nextPos = {
        {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};
public:
    int knightDialer(int n) {
        // memset(dp, -1, sizeof(dp));
        // vector<vector<int>> dp(n + 1, vector<int>(10, 0));
        
        // space optimization
        vector<int> prev(10, 1);
        // dp[i][j] : total ways to to make distinct phone number of len = i starting from j
        for(int i = 2; i <= n; ++i) {
            vector<int>curr(10, 0);
            for(int j = 0; j < 10; ++j) {
                int cnt = 0;
                for(int nPos : nextPos[j]) {
                    cnt = (cnt + prev[nPos]) % mod;
                }
                curr[j] = cnt;
            }
            prev = curr;
        }
        
        int ans = 0;
        for(int i = 0; i < 10; ++i) {
            ans = (ans + prev[i]) % mod;
        }
        return ans;
    }
};