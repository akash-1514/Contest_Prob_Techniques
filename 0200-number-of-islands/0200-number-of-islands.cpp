class Solution {
public:
    void dfs(vector<vector<char>>&grid, int x, int y) {
        int n = grid.size(), m = grid[0].size();
        grid[x][y] = '0';
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '1') {
                dfs(grid, nx, ny);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};