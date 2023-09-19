class Solution {
public:
    int maxUp = 35;
    long long ans_query(vector<vector<pair<long long, long long>>>&dp, int node, long long k) {
        if(k == 0) return 0;
        
        for(int i = 0; i < maxUp; ++i) {
            if((1ll << i) & k) {
                return dp[node][i].second + ans_query(dp, dp[node][i].first, k - (1ll << i));
            }
        }
        return 0;
    }
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n = receiver.size(), maxUp = ceil(log2(k));
        vector<vector<pair<long long, long long>>>dp(n, vector<pair<long long, long long>>(maxUp + 1));
        for(int i = 0; i < n; ++i) {
            dp[i][0] = {receiver[i], receiver[i]};
        }
        
        for(int i = 1; i <= maxUp; i++) {
            for(int j = 0; j < n; ++j) {
                int x = dp[j][i - 1].first;
                dp[j][i].first = dp[x][i - 1].first;
                dp[j][i].second = dp[j][i - 1].second + dp[x][i - 1].second;
            }
        }

        long long mx = 0;
        for(int i = 0; i < n; ++i) {
            long long score = i + ans_query(dp, i, k);
            mx = max(mx, score);
        }
        return mx;
    }
};