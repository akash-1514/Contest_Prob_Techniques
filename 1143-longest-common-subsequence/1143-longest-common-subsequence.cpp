class Solution {
public:
    vector<vector<int>>dp;
    int helper(string &s1, string &s2, int idx1, int idx2) {
        int n = s1.size(), m = s2.size();
        if(idx1 >= n || idx2 >= m) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s1[idx1] == s2[idx2]) {
            return dp[idx1][idx2] = 1 + helper(s1, s2, idx1 + 1, idx2 + 1);
        } else {
            return dp[idx1][idx2] = max(helper(s1, s2, idx1 + 1, idx2), helper(s1, s2, idx1, idx2 + 1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        dp.resize(n + 1, vector<int>(m + 1, -1));
        return helper(text1, text2, 0, 0);
    }
};