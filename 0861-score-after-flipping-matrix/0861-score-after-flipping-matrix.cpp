class Solution {
public:
    int matrixScore(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        for(int i = 0; i < n; ++i) {
            if(arr[i][0] == 0) {
                for(int j = 0; j < m; ++j) {
                    arr[i][j] = !arr[i][j];
                }
            }
        }
        
        for(int i = 1; i < m; ++i) {
            int ones = 0, zeros = 0;
            for(int j = 0; j < n; ++j) {
                if(arr[j][i] == 1) {
                    ones++;
                } else {
                    zeros++;
                }
            }
            
            if(zeros > ones) {
                for(int j = 0; j < n; ++j) {
                    arr[j][i] = !arr[j][i];
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int pow = 1;
            for(int j = m - 1; j >= 0; --j) {
                ans += pow * 1ll * arr[i][j];
                pow *= 2;
            }
        }
        
        return ans;
    }
};