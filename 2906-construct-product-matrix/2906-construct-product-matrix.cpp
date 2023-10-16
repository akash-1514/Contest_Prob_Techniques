class Solution {
public:
    const int mod = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> arr;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                arr.push_back(grid[i][j]);
            }
        }
        
        vector<int> prefix(n * m), suffix(n * m);
        prefix[0] = arr[0], suffix[n * m - 1] = arr[n * m - 1];
        for(int i = 1; i < n * m; ++i) {
            prefix[i] = (prefix[i - 1] * 1ll * arr[i]) % mod;
            suffix[n * m - i - 1] = (suffix[n * m - i] * 1ll * arr[n * m - i - 1]) % mod;
        }
        int idx = 0;
        vector<vector<int>>ans(n, vector<int>(m, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int left = (idx == 0) ? 1 : prefix[idx - 1];
                int right = (idx == n * m - 1) ? 1 : suffix[idx + 1];
                ans[i][j] = (left * 1ll * right) % mod;
                idx++;
            }
        }
        return ans;
    }
};