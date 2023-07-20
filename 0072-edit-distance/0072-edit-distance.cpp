class Solution {
public:
    vector<vector<int>>dp;
    int helper(string &s1, string &s2, int idx1, int idx2) {
        if(idx2 == s2.size()) {
            return s1.size() - idx1;
        }
        if(idx1 == s1.size()) {
            return s2.size() - idx2;
        }
        
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        if(s1[idx1] == s2[idx2]) {
            return dp[idx1][idx2] = helper(s1, s2, idx1 + 1, idx2 + 1);
        } else {
            return dp[idx1][idx2] = 1 + min({helper(s1, s2, idx1, idx2 + 1), helper(s1, s2, idx1 + 1, idx2), helper(s1, s2, idx1 + 1, idx2 + 1)});
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        dp.resize(n + 1, vector<int>(m + 1, -1));
        return helper(word1, word2, 0, 0);
    }
};