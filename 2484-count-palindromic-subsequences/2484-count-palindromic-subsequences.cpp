class Solution {
public:
    int dp[10001][10][10][6];
    const int mod = 1000000007;
    int helper(string &s, int idx, int first, int second, int len) {
        if(len == 5) return 1;
        if(idx >= s.size()) return 0;
        
        if(dp[idx][first][second][len] != -1) return dp[idx][first][second][len];
        
        int cnt = helper(s, idx + 1, first, second, len);
        if(len == 0) {
            cnt = (cnt + helper(s, idx + 1, s[idx] - '0', second, len + 1)) % mod;
        } else if(len == 1) {
            cnt = (cnt + helper(s, idx + 1, first, s[idx] - '0', len + 1)) % mod;
        } else if(len == 2) {
            cnt = (cnt + helper(s, idx + 1, first, second, len + 1)) % mod;
        } else if(len == 3 && (s[idx] - '0') == second) {
            cnt = (cnt + helper(s, idx + 1, first, second, len + 1)) % mod;
        } else if(len == 4 && (s[idx] - '0') == first) {
            cnt = (cnt + helper(s, idx + 1, first, second, len + 1)) % mod;
        }
        return dp[idx][first][second][len] = cnt;
    }
    int countPalindromes(string s) {
        memset(dp, -1, sizeof(dp));
        return helper(s, 0, 0, 0, 0);
    }
};