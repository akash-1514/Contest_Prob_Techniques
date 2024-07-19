class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int>ans;
        vector<int> cols(m, 0);
        for(int i = 0; i < m; ++i) {
            int mx = 0;
            for(int j = 0; j < n; ++j) {
                mx = max(mx, matrix[j][i]);
            }
            cols[i] = mx;
        }
        
        for(int i = 0; i < n; ++i) {
            int mn = matrix[i][0];
            int colIdx = 0;
            for(int j = 0; j < m; ++j) {
                if(matrix[i][j] < mn) {
                    mn = matrix[i][j];
                    colIdx = j;
                }
            }
            
            if(cols[colIdx] == mn) {
                ans.push_back(mn);
            }
        }
        
        return ans;
    }
};