class Solution {
public:
    int dp[6][51];
    int helper(string &s, int idx, int n) {
        if(n == 0) return 1;
        if(idx == s.size()) return 0;
        
        if(dp[idx][n] != -1) return dp[idx][n];
        
        int cnt = 0;
        
        cnt += helper(s, idx, n - 1);
        
        cnt += helper(s, idx + 1, n);
        
        return dp[idx][n] = cnt;
    }
    int countVowelStrings(int n) {
        memset(dp, -1, sizeof(dp));
        string s = "aeiou";
        return helper(s, 0, n);
    }
};