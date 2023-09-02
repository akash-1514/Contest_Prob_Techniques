class Solution {
public:
    unordered_map<string, int>mp;
    int dp[51];
    int helper(string s, int idx) {
        if(idx >= s.size()) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int mn = 1e9;
        mn = min(mn, 1 + helper(s, idx + 1));
        
        string res = "";
        for(int i = idx; i < s.size(); ++i) {
            res += s[i];
            if(mp[res] > 0) {
                mn = min(mn, helper(s, i + 1));
            }
        }
        
        return dp[idx] = mn;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto &str : dictionary) {
            mp[str]++;
        }
        
        memset(dp, -1, sizeof(dp));
        return helper(s, 0);
    }
};