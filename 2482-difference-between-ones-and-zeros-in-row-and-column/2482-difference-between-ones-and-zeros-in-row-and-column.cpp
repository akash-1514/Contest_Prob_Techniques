class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<pair<int, int>> row(n), col(m);
        for(int i = 0; i < n; ++i) {
            int ones = 0, zeros = 0;
            for(int j = 0; j < m; ++j) {
                ones += grid[i][j];
                zeros += (grid[i][j] == 0);
            }
            row[i] = {zeros, ones};
        }
        
        for(int i = 0; i < m; ++i) {
            int zeros = 0, ones = 0;
            for(int j = 0; j < n; ++j) {
                zeros += (grid[j][i] == 0);
                ones += grid[j][i];
            }
            col[i] = {zeros, ones};
        }
        
        vector<vector<int>>ans(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                ans[i][j] = row[i].second + col[j].second - row[i].first - col[j].first;
            }
        }
        
        return ans;
    }
};