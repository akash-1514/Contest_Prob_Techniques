class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int dfs(vector<vector<int>>&grid, int x, int y, vector<vector<int>>&vis) {
        int n = grid.size(), m = grid[0].size();
        vis[x][y] = 1;
        int mx = 0;
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] != 0 && !vis[nx][ny]) {
                mx = max(mx, dfs(grid, nx, ny, vis));
            }
        }
        vis[x][y] = 0;
        return mx + grid[x][y];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int mx = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 0) continue;
                mx = max(mx, dfs(grid, i, j, vis));
            }
        }
        return mx;
    }
};