class Solution {
public:
    int dp[101];
    int helper(string &s, int idx) {
        if(idx >= s.size()) return 1;
        if(s[idx] == '0') return 0;
        
        if(dp[idx] != -1) return dp[idx];

        int num = s[idx] - '0', cnt = 0;
        if(idx + 1 < s.size()) {
            num = num * 10 + (s[idx + 1] - '0');
            if(num <= 26) {
                cnt = (cnt + helper(s, idx + 2));
            } 
        }
        
        cnt = (cnt + helper(s, idx + 1));
        return dp[idx] = cnt;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return helper(s, 0);
    }
};