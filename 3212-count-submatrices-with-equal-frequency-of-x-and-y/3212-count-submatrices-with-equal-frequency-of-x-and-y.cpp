class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;
        vector<vector<vector<int>>> prefix(n + 1, vector<vector<int>>(m + 1, vector<int>(2, 0)));
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                prefix[i][j][0] = prefix[i - 1][j][0] + prefix[i][j - 1][0] - prefix[i - 1][j - 1][0] + (grid[i - 1][j - 1] == 'X');
                prefix[i][j][1] = prefix[i - 1][j][1] + prefix[i][j - 1][1] - prefix[i - 1][j - 1][1] + (grid[i - 1][j - 1] == 'Y');
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(i == 0 && j == 0) continue;
                int row1 = 1, col1 = 1, row2 = i + 1, col2 = j + 1;
                int countX = prefix[row2][col2][0] - prefix[row1 - 1][col2][0] - prefix[row2][col1 - 1][0] + prefix[row1 - 1][col1 - 1][0];
                int countY = prefix[row2][col2][1] - prefix[row1 - 1][col2][1] - prefix[row2][col1 - 1][1] + prefix[row1 - 1][col1 - 1][1];
                
                if(countX != 0 && countX == countY) {
                    ans++;
                }
            }
        }
        return ans;
    }
};