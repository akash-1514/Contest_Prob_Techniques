class Solution {
public:
    int dp[101][201];
    bool helper(string &s, int idx, int cnt) {
        if(idx >= s.size()) {
            if(cnt == 0) return true;
            return false;
        }
        
        if(dp[idx][cnt] != -1) return dp[idx][cnt];
        
        if(s[idx] == ')') {
            if(cnt > 0) {
                if(helper(s, idx + 1, cnt - 1)) return dp[idx][cnt] = true;
            }
        } else if(s[idx] == '(') {
            if(helper(s, idx + 1, cnt + 1)) return dp[idx][cnt] = true;
        } else {
            if(helper(s, idx + 1, cnt) || (cnt > 0 && helper(s, idx + 1, cnt - 1)) || helper(s, idx + 1, cnt + 1)) return dp[idx][cnt] = true;
        }
        return dp[idx][cnt] = false;
    }
    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp));
        return helper(s, 0, 0);
    }
};