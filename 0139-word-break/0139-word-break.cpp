class Solution {
private:
    unordered_map<string, int>mp;
public:
    int dp[301];
    bool helper(string &s, int idx) {
        if(idx >= s.size()) return true;
        if(dp[idx] != -1) return dp[idx];
        string word = "";
        for(int i = idx; i < s.size(); ++i) {
            word += s[i];
            if(mp[word] > 0) {
                if(helper(s, i + 1)) return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto &str : wordDict) {
            mp[str]++;
        }
        memset(dp, -1, sizeof(dp));
        return helper(s, 0);
    }
};