class Solution {
public:
    unordered_map<char, int>mp;
    vector<int> freq;
    int dp[26][26];
    int mod = 1e9 + 7;
    int helper(int idx, int cnt, int k) {
        if(idx >= freq.size()) {
            return cnt == k;
        }
        
        if(cnt > k) return 0;
        
        if(dp[idx][cnt] != -1) return dp[idx][cnt];
        
        int ans = 0;
        if(freq[cnt] == freq[idx]) {
            ans = (ans + freq[cnt] * 1ll * helper(idx + 1, cnt + 1, k)) % mod;
        }
        
        ans = (ans + helper(idx + 1, cnt, k)) % mod;
        return dp[idx][cnt] = ans;
    }
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        for(char ch : s) mp[ch]++;
        if(mp.size() < k) return 0;
        for(auto &it : mp) freq.push_back(it.second);
        sort(freq.rbegin(), freq.rend());
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, k);
    }
};