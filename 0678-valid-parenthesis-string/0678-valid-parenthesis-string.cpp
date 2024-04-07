class Solution {
public:
    int dp[101][101];
    bool helper(string &s, int idx, int open) {
        if(idx >= s.size()) {
            return open == 0;
        }
        
        if(dp[idx][open] != -1) return dp[idx][open];
        
        bool ans = false;
        if(s[idx] == '(') {
            ans |= helper(s, idx + 1, open + 1);
        } else if(s[idx] == ')') {
            if(open > 0) {
                ans |= helper(s, idx + 1, open - 1);
            } 
        } else {
            ans |= helper(s, idx + 1, open + 1);
            if(open > 0) {
                ans |= helper(s, idx + 1, open - 1);
            }
            ans |= helper(s, idx + 1, open);
        }
        
        return dp[idx][open] = ans;
    }
    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp));
        return helper(s, 0, 0);
    }
};