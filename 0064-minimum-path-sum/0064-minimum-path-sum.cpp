class Solution {
public:
    int dp[201][201];
    int helper(vector<vector<int>>&grid, int x, int y) {
        int n = grid.size(), m = grid[0].size();
        if(x == n - 1 && y == m - 1) {
            return grid[x][y];
        }
        
        if(dp[x][y] != -1) return dp[x][y];
        
        int mn = 1e9;
        if(x + 1 < n) {
            mn = min(mn, grid[x][y] + helper(grid, x + 1, y));
        }
        if(y + 1 < m) {
            mn = min(mn, grid[x][y] + helper(grid, x, y + 1));
        }
        return dp[x][y] = mn;
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return helper(grid, 0, 0);
    }
};