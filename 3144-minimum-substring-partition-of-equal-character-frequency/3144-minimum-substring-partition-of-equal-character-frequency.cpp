class Solution {
public:
    int dp[1001];
    int helper(string &s, int idx) {
        if(idx >= s.size()) {
            return 0;
        }
        
        if(dp[idx] != -1) return dp[idx];
        
        int mn = 1e9;
        
        vector<int> freq(26, 0);
        for(int i = idx; i < s.size(); ++i) {
            freq[s[i] - 'a']++;
            int prev = -1;
            bool fl = true;
            for(int j = 0; j < 26; ++j) {
                if(freq[j] != 0) {
                    if(prev == -1) {
                        prev = freq[j];
                    } else if(prev != freq[j]) {
                        fl = false;
                        break;
                    }
                }
            }
            
            if(fl) {
                mn = min(mn, 1 + helper(s, i + 1));
            }
        }
        return dp[idx] = mn;
    }
    int minimumSubstringsInPartition(string s) {
        memset(dp, -1, sizeof(dp));
        return helper(s, 0);
    }
};