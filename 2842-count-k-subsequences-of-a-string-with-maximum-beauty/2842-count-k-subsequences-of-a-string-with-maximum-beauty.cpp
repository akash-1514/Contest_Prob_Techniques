class Solution {
public:
    unordered_map<char, int>mp;
    int mod = 1e9 + 7;
    unordered_map<string, int>dp;
    int helper(int idx, int k, int maxBeauty) {
        if(k == 0) {
            if(maxBeauty == 0) return 1;
            return 0;
        }
        if(idx >= 26) {
            return 0;
        }
        
        string state = to_string(idx) + "," + to_string(k) + to_string(maxBeauty);
        if(dp.find(state) != dp.end()) return dp[state];
         
        int ans = 0;
        
        if(mp[idx + 'a'] > 0) {
            ans = (ans + mp[idx + 'a'] * 1ll * helper(idx + 1, k - 1, maxBeauty - mp[idx + 'a'])) % mod;
        }
        
        ans = (ans + helper(idx + 1, k, maxBeauty)) % mod;
        return dp[state] = ans;
    }
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        for(char ch : s) mp[ch]++;
        if(mp.size() < k) return 0;
        priority_queue<int>pq;
        for(auto &it : mp) pq.push(it.second);
        int maxBeauty = 0;
        int cnt = 0;
        while(!pq.empty() && cnt < k) {
            maxBeauty += pq.top();
            pq.pop();
            cnt++;
        }
        
        return helper(0, k, maxBeauty);
    }
};