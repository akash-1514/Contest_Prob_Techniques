class Solution {
public:
    int mod = 1e9 + 7;
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; ++i) {
            dp[i] = (2 * 1ll * dp[i - 1]) % mod;
            if(freq[s[i - 1] - 'a'] != 0) {
                dp[i] = (dp[i] - dp[freq[s[i - 1] - 'a'] - 1] + mod) % mod;
            }
            freq[s[i - 1] - 'a'] = i;
        }
        return (dp[n] - 1 + mod) % mod;
    }
};