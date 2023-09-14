class Solution {
public:
    int dp[101][101];
    int helper(vector<int>&cuts, int i, int j) {
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int minCost = 1e9;
        for(int k = i; k <= j; ++k) {
            int cost = (cuts[j + 1] - cuts[i - 1]) + helper(cuts, i, k - 1) + helper(cuts, k + 1, j);
            minCost = min(minCost, cost);
        }
        return dp[i][j] = minCost;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        memset(dp, -1, sizeof(dp));
        return helper(cuts, 1, cuts.size() - 2);
    }
};