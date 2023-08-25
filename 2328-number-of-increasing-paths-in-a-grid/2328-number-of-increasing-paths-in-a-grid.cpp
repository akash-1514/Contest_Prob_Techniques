class Solution {
public:
    int mod = 1e9 + 7;
    int dp[1001][1001];
    int helper(vector<vector<int>>&grid, int x, int y) {
        
        if(dp[x][y] != -1) return dp[x][y];
        
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        int cnt = 1;
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] > grid[x][y]) {
                cnt = (cnt + helper(grid, nx, ny)) % mod;
            }
        }
        return dp[x][y] = cnt;
    }
    int countPaths(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                ans = (ans + helper(grid, i, j)) % mod;
            }
        }
        return ans;
    }
};