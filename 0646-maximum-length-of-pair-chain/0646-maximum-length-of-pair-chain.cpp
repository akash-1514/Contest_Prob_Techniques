class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        int mx = 1;
        vector<int> dp(n, 1);
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};