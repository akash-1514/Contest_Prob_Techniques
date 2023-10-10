class Solution {
private:
    int obs = 0;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    int helper(vector<vector<int>>&arr, int x, int y, int ex, int ey, int cnt, vector<vector<int>>&vis) {
        int n = arr.size(), m = arr[0].size();
        if(x == ex && y == ey) {
            if(cnt == (n * m - obs - 1)) {
                return 1;
            }
            return 0;
        }
        
        int paths = 0;
        
        vis[x][y] = 1;        
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && arr[nx][ny] != -1 && !vis[nx][ny]) { 
                paths += helper(arr, nx, ny, ex, ey, cnt + 1, vis);
            }
        }
        vis[x][y] = 0;
        return paths;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), sx, sy, ex, ey;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 2) {
                    ex = i, ey = j;
                } else if(grid[i][j] == 1) {
                    sx = i, sy = j;
                } else if(grid[i][j] == -1) {
                    obs++;
                }
            }
        }
        
        vector<vector<int>>vis(n, vector<int>(m, 0));
        return helper(grid, sx, sy, ex, ey, 0, vis);
    }
};