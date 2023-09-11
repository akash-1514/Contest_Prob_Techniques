class Solution {
public:
    vector<vector<int>>dp;
    bool helper(string &s, string &p, int idx1, int idx2) {
        if(idx1 == s.size() && idx2 == p.size()) return true;
        if(idx1 == s.size()) {
            for(int i = idx2; i < p.size(); ++i) {
                if(p[i] != '*') return false;
            }
            return true;
        }
        if(idx2 == p.size()) {
            return false;
        }
        
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        if(p[idx2] == '*' || p[idx2] == '?') {
            if(p[idx2] == '*') {
                int i = idx1;
                while(i <= s.size()) {
                    if(helper(s, p, i, idx2 + 1)) return dp[idx1][idx2] = true;
                    i++;
                } 
            } else {
                if(helper(s, p, idx1 + 1, idx2 + 1)) return dp[idx1][idx2] = true;
            }
        } else {
            if(p[idx2] == s[idx1]) {
                if(helper(s, p, idx1 + 1, idx2 + 1)) return dp[idx1][idx2] = true;
            } else {
                return dp[idx1][idx2] = false;
            }
        }
        return dp[idx1][idx2] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        dp.resize(n, vector<int>(m, -1));
        return helper(s, p, 0, 0);
    }
};