class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        vector<vector<int>>freq(26, vector<int>(2, -1));
        
        dp[0] = 1;
        freq[s[0] - 'A'][0] = 0;
        freq[s[0] - 'A'][1] = -1;
        int ans = 1;
        for(int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1] + (i - freq[s[i] - 'A'][0]) - (freq[s[i] - 'A'][0] - freq[s[i] - 'A'][1]);
            freq[s[i] - 'A'][1] = freq[s[i] - 'A'][0];
            freq[s[i] - 'A'][0] = i;
            ans += dp[i];
        }
        return ans;
    }
};