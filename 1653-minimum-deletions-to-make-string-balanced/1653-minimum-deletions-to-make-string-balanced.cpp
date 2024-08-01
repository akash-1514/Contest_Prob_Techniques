class Solution {
public:
    int dp[100001][2];
    int helper(string &s, int idx, bool fl) {
        if(idx >= s.size()) {
            return 0;
        }
        
        if(dp[idx][fl] != -1) return dp[idx][fl];
        
        int ans = 0;
        
        if(fl) {
            if(s[idx] == 'b') {
                ans = max(ans, 1 + helper(s, idx + 1, fl));
            }
        } else {
            if(s[idx] == 'a') {
                ans = max(ans, 1 + helper(s, idx + 1, fl));
                ans = max(ans, 1 + helper(s, idx + 1, true));
            } else {
                ans = max(ans, 1 + helper(s, idx + 1, true));
            }
        }
        
        ans = max(ans, helper(s, idx + 1, fl));
        
        return dp[idx][fl] = ans;
    }
    int minimumDeletions(string s) {
        memset(dp, -1, sizeof(dp));
        return s.size() - helper(s, 0, false);
    }
};