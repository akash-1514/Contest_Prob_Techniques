class Solution {
public:
    static bool cmp(string &w1, string &w2) {
        return w1.size() < w2.size();
    }
    bool check(string &s1, string &s2) {
        if(s1.size() == s2.size() || s1.size() + 1 != s2.size()) return false;
        int i = 0, j = 0;
        while(i < s1.size() && j < s2.size()) {
            if(s2[j] == s1[i]) {
                i++;
            }
            j++;
        }
        return i == s1.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), cmp);
        vector<int> dp(n, 1);
        int mx = 1;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(check(words[j], words[i])) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};