class Solution {
public:
    vector<vector<int>>dp;
    
    int helper(vector<vector<int>>&grid, int x, int y) {
        int n = grid.size(), m = grid[0].size();
        
        if(x == n - 1 && y == m - 1) return 0;
        
        if(dp[x][y] != -1e9) return dp[x][y];
        
        int mx = -1e9;
        
        if(x + 1 < n) {
            mx = max(mx, (grid[x + 1][y] - grid[x][y]));
            mx = max(mx, (grid[x + 1][y] - grid[x][y]) + helper(grid, x + 1, y));
        }
        
        if(y + 1 < m) {
            mx = max(mx, (grid[x][y + 1] - grid[x][y]));
            mx = max(mx, (grid[x][y + 1] - grid[x][y]) + helper(grid, x, y + 1));
        }
        
        return dp[x][y] = mx;
    }
    
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        dp.resize(n, vector<int>(m, -1e9));
        int mx = -1e9;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(i == n - 1 && j == m - 1) continue;
                int res = helper(grid, i, j);
                mx = max(mx, res);      
            }
        }
        return mx;
    }
};