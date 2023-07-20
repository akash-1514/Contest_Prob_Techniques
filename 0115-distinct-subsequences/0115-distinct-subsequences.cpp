class Solution {
public:
    vector<vector<int>>dp;
    int helper(string &s, string &t, int idx1, int idx2) {
        if(idx2 == t.size()) return 1;
        if(idx1 == s.size()) return 0;
        
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        if(s[idx1] == t[idx2]) {
            return dp[idx1][idx2] = helper(s, t, idx1 + 1, idx2 + 1) + helper(s, t, idx1 + 1, idx2);
        } else {
            return dp[idx1][idx2] = helper(s, t, idx1 + 1, idx2);
        }
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        dp.resize(n + 1, vector<int>(m + 1, -1));
        return helper(s, t, 0, 0);
    }
};