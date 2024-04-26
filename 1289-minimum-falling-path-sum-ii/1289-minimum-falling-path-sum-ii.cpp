class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<vector<int>>&grid, int r, int prev) {
        if(r >= grid.size()) return 0;
        
        if(dp[r][prev] != 1e9) return dp[r][prev];
        
        int mn = 1e8;
        for(int j = 1; j <= grid[0].size(); ++j) {
            if(j == prev) continue;
            mn = min(mn, grid[r][j - 1] + helper(grid, r + 1, j));
        }
        return dp[r][prev] = mn;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        dp.resize(n, vector<int>(m + 1, 1e9));
        return helper(grid, 0, 0);
    }
};