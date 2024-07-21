class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>>ans(n, vector<int>(m, 0));
        vector<long long> temp(m, 0);
        for(int i = 0; i < n; ++i) {
            ans[i][0] = rowSum[i];
            temp[0] += rowSum[i];
        }
        
        for(int i = 0; i < m - 1; ++i) {
            if(temp[i] == colSum[i]) break;
            long long diff = temp[i] - colSum[i];
            for(int j = 0; j < n; ++j) {
                if(ans[j][i] < diff) {
                    diff -= ans[j][i];
                    ans[j][i + 1] = ans[j][i];
                    temp[i + 1] += ans[j][i];
                    ans[j][i] = 0;
                } else if(ans[j][i] >= diff) {
                    ans[j][i + 1] = diff;
                    ans[j][i] -= diff;
                    temp[i + 1] += diff;
                    break;
                }
            }
        }
        return ans;
    }
};