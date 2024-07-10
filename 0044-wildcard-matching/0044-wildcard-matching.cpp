class Solution {
public:
    vector<vector<int>>dp;
    bool helper(string &s, string &p, int i, int j) {
        if(j >= p.size() && i >= s.size()) return true;
        if(j >= p.size()) return false;
        if(i >= s.size()) {
            bool fl = true;
            for(int k = j; k < p.size(); ++k) {
                if(p[k] != '*') {
                    fl = false;
                    break;
                }
            }
            return fl;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(p[j] == '*') {
            if(helper(s, p, i + 1, j)) return dp[i][j] = true;
            if(helper(s, p, i, j + 1)) return dp[i][j] = true;
        } else if(s[i] == p[j] || p[j] == '?') {
            if(helper(s, p, i + 1, j + 1)) return dp[i][j] = true;
        }
        
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        dp.resize(n + 1, vector<int>(m + 1, -1));
        return helper(s, p, 0, 0);
    }
};