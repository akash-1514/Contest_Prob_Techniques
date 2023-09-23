class Solution {
public:
    #define maxUp 33
    long long ans_query(vector<vector<pair<int, long long>>>&dp, int node, long long k) {
        for(int i = maxUp; i >= 0; --i) {
            if((k & (1ll << i)) != 0) {
                return dp[node][i].second + ans_query(dp, dp[node][i].first, k - (1ll << i));
            }
        }
        return 0;
    }
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n = receiver.size();
        
        vector<vector<pair<int, long long>>>dp(n, vector<pair<int, long long>>(maxUp + 1));
        
        for(int i = 0; i < n; ++i) {
            dp[i][0] = {receiver[i], receiver[i]};
        }
        
        // kth parent of each node and score from a node to its kth parent
        for(int j = 1; j <= maxUp; ++j) {
            for(int i = 0; i < n; ++i) {
                dp[i][j].first = dp[dp[i][j - 1].first][j - 1].first;
                dp[i][j].second = dp[i][j - 1].second + dp[dp[i][j - 1].first][j - 1].second;
            }
        }
        
        long long mx = 0;
        for(int i = 0; i < n; ++i) {
            mx = max(mx, i + ans_query(dp, i, k));
        }
        return mx;
    }
};