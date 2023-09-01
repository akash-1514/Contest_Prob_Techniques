class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n + 1, 0);
        for(int i = 0; i <= n; ++i) {
            int res = 0;
            for(int j = 0; j < 32; ++j) {
                if((i & (1 << j)) != 0) {
                    res++;
                }
            }
            ans[i] = res;
        }
        return ans;
    }
};