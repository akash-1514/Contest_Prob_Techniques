class Solution {
public:
    int dp[11][11][11][2][2][20];
    int helper(string &s, int idx, int k, int even, int odd, bool tight, bool leading, int res) {
        if(idx >= s.size()) {
            if(res == 0 && !leading) {
                if(even == odd) {
                    
                    return 1;
                }
            }
            return 0;
        }
        
        if(dp[idx][even][odd][tight][leading][res] != -1) return dp[idx][even][odd][tight][leading][res];
        
        int cnt = 0;
        int high = (tight) ? s[idx] - '0' : 9;
        for(int i = 0; i <= high; ++i) {
            bool f = ((!leading || i != 0) && (i % 2 == 0));
            cnt += helper(s, idx + 1, k, even + f, odd + (i % 2 != 0), tight & (i == high), leading & (i == 0), (res * 10 + i) % k);
        }
        return dp[idx][even][odd][tight][leading][res] = cnt;
        // return cnt;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string s1 = to_string(low - 1);
        string s2 = to_string(high);
        
        memset(dp, -1, sizeof(dp));
        int res1 = helper(s1, 0, k, 0, 0, true, true, 0);
        
        memset(dp, -1, sizeof(dp));
        int res2 = helper(s2, 0, k, 0, 0, true, true, 0);
        
        return res2 - res1;
    }
};