class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                for(int i1 = i; i1 < n; ++i1) {
                    for(int j1 = j; j1 < m; ++j1) {
                        int rangeSum = prefix[i1 + 1][j1 + 1] - prefix[i1 + 1][j] - prefix[i][j1 + 1] + prefix[i][j];
                        if(rangeSum == target) ans++;
                    }
                }
            }
        }
        return ans;
    }
};