class Solution {
private:
    vector<string>ans;
    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    void helper(string &s, int idx, string &res) {
        if(idx >= s.size()) {
            ans.push_back(res);
            return;
        }
        
        string key = keypad[s[idx] - '0'];
        for(int i = 0; i < key.size(); ++i) {
            res.push_back(key[i]);
            helper(s, idx + 1, res);
            res.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        string res = "";
        helper(digits, 0, res);
        return ans;
    }
};