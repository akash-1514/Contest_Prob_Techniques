class Solution {
public:
    int dp[71][71][71];
    int helper(vector<vector<int>>&grid, int x, int y1, int y2) {
        int n = grid.size(), m = grid[0].size();
        if(x == n - 1) {
            if(y1 == y2) return grid[x][y1];
            else return grid[x][y1] + grid[x][y2];
        }
        
        if(dp[x][y1][y2] != -1) return dp[x][y1][y2];
        
        int mx = 0;
        int dy[] = {-1, 0, 1};
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(y1 + dy[i] >= 0 && y1 + dy[i] < m) {
                    if(y2 + dy[j] >= 0 && y2 + dy[j] < m) {
                        if(y1 == y2) {
                            mx = max(mx, grid[x][y1] + helper(grid, x + 1, y1 + dy[i], y2 + dy[j]));
                        } else {
                            mx = max(mx, grid[x][y1] + grid[x][y2] + helper(grid, x + 1, y1 + dy[i], y2 + dy[j]));
                        }
                    }
                }
            }
        }
        return dp[x][y1][y2] = mx;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return helper(grid, 0, 0, grid[0].size() - 1);
    }
};