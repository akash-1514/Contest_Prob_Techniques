class Solution {
public:
    int cells = 0;
    int helper(vector<vector<int>>&grid, vector<vector<int>>&vis, int x, int y, int cnt) {
        if(grid[x][y] == 2) {
            if(cnt == cells - 1) {
                return 1;
            } 
            return 0;
        }
        int ways = 0;
        vis[x][y] = 1;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && !vis[nx][ny] && grid[nx][ny] != -1) {
                ways += helper(grid, vis, nx, ny, cnt + 1);
            }
        }
        vis[x][y] = 0;
        return ways;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int sx = -1, sy = -1;
        for(int  i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] != -1) cells++;
                if(grid[i][j] == 1) {
                    sx = i, sy = j;
                }
            }
        }
        
        
        vector<vector<int>>vis(n, vector<int>(m, 0));
        
        return helper(grid, vis, sx, sy, 0);
    }
};