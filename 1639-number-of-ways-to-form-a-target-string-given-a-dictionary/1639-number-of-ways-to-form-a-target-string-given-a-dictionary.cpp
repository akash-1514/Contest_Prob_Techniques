class Solution {
public:
    int mod = 1e9 + 7;
    int dp[1001][1001];
    vector<vector<int>>vec;
    int helper(int m, string &target, int idx1, int idx2) {
        if(idx2 >= target.size()) return 1;
        if(idx1 >= m) return 0;
        
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        int cnt = 0;
        if(vec[idx1][target[idx2] - 'a'] != 0) {
            cnt = (cnt + (vec[idx1][target[idx2] - 'a'] * 1ll * helper(m, target, idx1 + 1, idx2 + 1))) % mod;
        }
        cnt = (cnt + helper(m, target, idx1 + 1, idx2)) % mod; 
        return dp[idx1][idx2] = cnt;
    }
    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        vec.resize(n, vector<int>(26, 0));
        for(int i = 0; i < words.size(); ++i) {
            for(int j = 0; j < words[i].size(); ++j) {
                vec[j][words[i][j] - 'a']++;
            }
        }
        memset(dp, -1, sizeof(dp));
        return helper(n, target, 0, 0);
    }
};