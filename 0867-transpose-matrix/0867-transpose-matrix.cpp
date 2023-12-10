class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>>vec(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) { // col
            for(int j = 0; j < n; ++j) { // row
                vec[i][j] = matrix[j][i];
            }
        }
        return vec;
    }
};