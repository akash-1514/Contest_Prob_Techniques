class Solution {
public:
    // vector<vector<int>> prefix;
    // vector<vector<int>> vis;
    void dfs(vector<vector<int>>&grid, int x, int y, pair<int, int>&p) {
        int n = grid.size(), m = grid[0].size();
        grid[x][y] = 0;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        
        p = max(p, {x, y});
        
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if(grid[nx][ny] == 1) {
                    dfs(grid, nx, ny, p);
                }
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();
        // prefix.resize(n + 1, vector<int>(m + 1, 0));
        // for(int i = 0; i < n; ++i) {
        //     for(int j = 0; j < m; ++j) {
        //         if(grid[i][j] == 0) prefix[i + 1][j + 1] = 1;
        //     }
        // }
        
        // for(int i = 1; i <= n; ++i) {
        //     for(int j = 1; j <= m; ++j) {
        //         prefix[i][j] += prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        //     }
        // }
        
        // vis.resize(n, vector<int>(m, 0));
        
        vector<vector<int>>ans;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(land[i][j] == 1) {
                    vector<int> res = {i, j};
                    pair<int, int>p = {i, j};
                    dfs(land, i, j, p);
                    res.push_back(p.first);
                    res.push_back(p.second);
                    ans.push_back(res);
                }
            }
        }
        return ans;
    }
};