class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> row(n, 0), col(m, 0);
        for(int i = 0; i < n; ++i) {
            int cnt = 0;
            for(int j = 0; j < m; ++j) {
                cnt += (mat[i][j] == 1);
            }
            row[i] = cnt;
        }
        
        for(int i = 0; i < m; ++i) {
            int cnt = 0;
            for(int j = 0; j < n; ++j) {
                cnt += (mat[j][i] == 1);
            }
            col[i] = cnt;
        }
        
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(mat[i][j] == 1 && col[j] == 1 && row[i] == 1) ans++;
            }
        }
        return ans;
    }
};