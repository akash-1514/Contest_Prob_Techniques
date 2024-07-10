class Solution {
public:
    int dp[1001][1001];
    int helper(string &s, string& t, int idx1, int idx2) {
        if(idx2 >= t.size()) {
            return 1;
        }
        
        if(idx1 >= s.size()) {
            return 0;
        }
        
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        int ways = 0;
        if(s[idx1] == t[idx2]) {
            ways += helper(s, t, idx1 + 1, idx2 + 1);
        }
        
        ways += helper(s, t, idx1 + 1, idx2);
        return dp[idx1][idx2] = ways;
    }
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return helper(s, t, 0, 0);
    }
};