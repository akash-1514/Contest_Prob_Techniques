class Solution {
public:
    unordered_map<string, int>mp;
    void helper(string &s, int idx, vector<string>&ans, string &res) {
        if(idx >= s.size()) {
            res.pop_back();
            ans.push_back(res);
            res += " ";
            return;
        }
        
        string sub = "";
        for(int i = idx; i < s.size(); ++i) {
            sub += s[i];
            if(mp[sub] > 0) {
                string str = res;
                str += (sub + " ");
                helper(s, i + 1, ans, str);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto &w : wordDict) {
            mp[w]++;
        }
        vector<string>ans;
        string res = "";
        helper(s, 0, ans, res);
        return ans;
    }
};