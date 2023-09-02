class Solution {
public:
    const int mod = 1e9 + 7;
    unordered_map<string, int>dp;
    int helper(vector<int>&freq, int idx, int k, int mx) {
        if(k == 0) {
            if(mx == 0) return 1;
            return 0;
        }
        
        if(idx >= 26 || mx < 0) return 0;
        
        string seen = to_string(idx) + "," + to_string(k) + "," + to_string(mx);
        
        if(dp.find(seen) != dp.end()) return dp[seen];
        
        long long cnt = 0;
        if(freq[idx] != 0) {
            cnt = (cnt + freq[idx] * 1ll * helper(freq, idx + 1, k - 1, mx - freq[idx])) % mod;
        }
        
        cnt = (cnt + helper(freq, idx + 1, k, mx)) % mod;
        return dp[seen] = cnt;
    }
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        vector<int> freq(26, 0);
        for(char ch : s) {
            freq[ch - 'a']++;
        }
        
        vector<int>vec;
        for(int i = 0; i < 26; ++i) {
            if(freq[i] != 0) {
                vec.push_back(freq[i]);
            }
        }
        
        if(vec.size() < k) return 0;
        
        sort(vec.begin(), vec.end());
        
        int mx = 0, temp = k;
        for(int i = vec.size() - 1; i >= 0 && temp-- > 0; --i) {
            mx += vec[i];
        }

        return helper(freq, 0, k, mx);
    }
};