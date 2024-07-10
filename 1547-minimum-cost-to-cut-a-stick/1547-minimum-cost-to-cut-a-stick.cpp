class Solution {
public:
    int dp[101][101];
    int helper(vector<int>&cost, int l, int r) {
        if(l > r) {
            return 0;
        }
        
        if(dp[l][r] != -1) return dp[l][r];
        
        int mn = 1e9;
        for(int i = l; i <= r; ++i) {
            int res = cost[r + 1] - cost[l - 1];
            mn = min(mn, res + helper(cost, l, i - 1) + helper(cost, i + 1, r));
        }
        return dp[l][r] = mn;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        
        memset(dp, -1, sizeof(dp));
        
        
        return helper(cuts, 1, cuts.size() - 2);
    }
};