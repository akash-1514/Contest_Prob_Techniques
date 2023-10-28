class Solution {
public:
    int mod = 1e9 + 7;
    int dp[20001][26];
    int helper(int n, int idx, int prev) {
        if(idx > n) return 1;
        
        if(dp[idx][prev] != -1) return dp[idx][prev];
        
        int cnt = 0;
        if(idx == 1) {
            cnt = (cnt + helper(n, idx + 1, 'a' - 'a')) % mod;
            cnt = (cnt + helper(n, idx + 1, 'e' - 'a')) % mod;
            cnt = (cnt + helper(n, idx + 1, 'i' - 'a')) % mod;
            cnt = (cnt + helper(n, idx + 1, 'o' - 'a')) % mod;
            cnt = (cnt + helper(n, idx + 1, 'u' - 'a')) % mod;
        } else {
            if(prev + 'a' == 'a') {
                cnt = (cnt + helper(n, idx + 1, 'e' - 'a')) % mod;
            }
            // case1 
            if(prev + 'a' == 'e') {
                cnt = (cnt + helper(n, idx + 1, 'a' - 'a')) % mod;
                cnt = (cnt + helper(n, idx + 1, 'i' - 'a')) % mod;
            }
            
            if(prev + 'a' == 'i') {
                cnt = (cnt + helper(n, idx + 1, 'a' - 'a')) % mod;
                cnt = (cnt + helper(n, idx + 1, 'e' - 'a')) % mod;
                cnt = (cnt + helper(n, idx + 1, 'o' - 'a')) % mod;
                cnt = (cnt + helper(n, idx + 1, 'u' - 'a')) % mod;
            }
            
            if(prev + 'a' == 'o') {
                cnt = (cnt + helper(n, idx + 1, 'i' - 'a')) % mod;
                cnt = (cnt + helper(n, idx + 1, 'u' - 'a')) % mod;
            }
            
            if(prev + 'a' == 'u') {
                cnt = (cnt + helper(n, idx + 1, 'a' - 'a')) % mod;
            }
        }
        return dp[idx][prev] = cnt;
    }
    int countVowelPermutation(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(n, 1, 0);
    }
};