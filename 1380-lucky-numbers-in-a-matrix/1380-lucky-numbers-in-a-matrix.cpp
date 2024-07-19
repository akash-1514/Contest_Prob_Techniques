class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int colMx = 1e9;
        for(int i = 0; i < m; ++i) {
            int mx = 0;
            for(int j = 0; j < n; ++j) {
                mx = max(mx, matrix[j][i]);
            }
            colMx = min(colMx, mx);
        }
        
        int rowMn = -1e9;
        for(int i = 0; i < n; ++i) {
            int mn = matrix[i][0];
            for(int j = 0; j < m; ++j) {
                mn = min(mn, matrix[i][j]);
            }
            rowMn = max(rowMn, mn);
            if(rowMn == colMx) {
                return {colMx};
            }
        }
        
        return {};
    }
};