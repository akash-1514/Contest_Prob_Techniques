class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size(), m = bank[0].size();
        int prev = 0, ans = 0;
        for(int i = 0; i < n; ++i) {
            int cnt = 0;
            for(int j = 0; j < m; ++j) {
                cnt += (bank[i][j] - '0');
            }
            ans += prev * cnt;
            if(cnt > 0) {
                prev = cnt;
            }
        }
        return ans;
    }
};