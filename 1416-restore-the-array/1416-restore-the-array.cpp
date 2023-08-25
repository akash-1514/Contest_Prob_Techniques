class Solution {
public:
    int mod = 1e9 + 7;
    int dp[100001];
    int helper(string &s, int idx, int k) {
        if(idx >= s.size()) return 1;
        if(s[idx] == '0') return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        long long num = 0, cnt = 0;
        for(int i = idx; i < s.size(); ++i) {
            num = num * 1ll * 10 + (s[i] - '0');
            if(num <= k) {
                cnt = (cnt + helper(s, i + 1, k)) % mod;
            } else {
                break;
            }
        }
        return dp[idx] = cnt;
    }
    int numberOfArrays(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return helper(s, 0, k);
    }
};