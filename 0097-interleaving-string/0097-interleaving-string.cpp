class Solution {
public:
    int dp[101][101];
    int helper(string &s1, string &s2, string &s3, int idx1, int idx2) {
        if(idx1 >= s1.size() && idx2 >= s2.size()) return true;
        
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        if(idx1 < s1.size() && s3[idx1 + idx2] == s1[idx1]) {
            if(helper(s1, s2, s3, idx1 + 1, idx2)) return dp[idx1][idx2] = true;
        }
        
        if(idx2 < s2.size() && s3[idx1 + idx2] == s2[idx2]) {
            if(helper(s1, s2, s3, idx1, idx2 + 1)) return dp[idx1][idx2] = true;
        }
        
        return dp[idx1][idx2] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        memset(dp, -1, sizeof(dp));
        if(n1 + n2 != n3) return false;
        return helper(s1, s2, s3, 0, 0);
    }
};