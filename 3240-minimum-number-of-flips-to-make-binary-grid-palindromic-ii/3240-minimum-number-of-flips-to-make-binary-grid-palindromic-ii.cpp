class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n / 2; ++i) {
            for(int j = 0; j < m / 2; ++j) {
                int a = grid[i][j], b = grid[i][m - j - 1], c = grid[n - i - 1][j], d = grid[n - i - 1][m - j - 1];
                
                int ones = a + b + c + d;
                int zeros = 4 - ones;
                
                ans += 4 - max(ones, zeros);
            }
        }
        
        if(n % 2 != 0 && m % 2 != 0) {
            int pair = 0, error = 0;
            for(int i = 0; i < n / 2; ++i) {
                if(grid[i][m / 2] == grid[n - i - 1][m / 2] && grid[i][m / 2] == 1) {
                    pair++;
                } else if(grid[i][m / 2] != grid[n - i - 1][m / 2]) {
                    error++;
                }
            }
            
            for(int i = 0; i < m / 2; ++i) {
                if(grid[n / 2][i] == grid[n / 2][m - i - 1] && grid[n / 2][i] == 1) {
                    pair++;
                } else if(grid[n / 2][i] != grid[n / 2][m - i - 1]) {
                    error++;
                }
            }
            
            int res = 1e9;
            
            if(((pair + error) * 2) % 4 == 0) {
                res = min(res, error + (grid[n / 2][m / 2] == 1));
            } else {
                if(error == 0) {
                    res = min(res, 2 + (grid[n / 2][m / 2] == 1));
                } else {
                    res = min(res, error + (grid[n / 2][m / 2] == 1));
                }
            }
            
            ans += res;
        } else if(n % 2 != 0) {
            int pair = 0, error = 0;
            for(int i = 0; i < m / 2; ++i) {
                if(grid[n / 2][i] == grid[n / 2][m - i - 1] && grid[n / 2][i] == 1) {
                    pair++;
                } else if(grid[n / 2][i] != grid[n / 2][m - i - 1]) {
                    error++;
                }
            }
            
            int res = 1e9;
            if(((pair + error) * 2) % 4 == 0) {
                res = min(res, error);
            } else {
                if(error == 0) {
                    res = min(res, 2);
                } else {
                    res = min(res, error);
                }
            }
            
            ans += res;
            
        } else if(m % 2 != 0) {
            int pair = 0, error = 0;
            for(int i = 0; i < n / 2; ++i) {
                if(grid[i][m / 2] == grid[n - i - 1][m / 2] && grid[i][m / 2] == 1) {
                    pair++;
                } else if(grid[i][m / 2] != grid[n - i - 1][m / 2]) {
                    error++;
                }
            }
            
            int res = 1e9;
            if(((pair + error) * 2) % 4 == 0) {
                res = min(res, error);
            } else {
                if(error == 0) {
                    res = min(res, 2);
                } else {
                    res = min(res, error);
                }
            }
            
            ans += res;
        }
        
        return ans;
    }
};