class Solution {
public:
    long long wonderfulSubstrings(string s) {
        int n = s.size();
        vector<int> freq(10, 0);
        unordered_map<int, int>mp;
        mp[0] = 1;
        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            freq[s[i] - 'a']++;
            for(int j = 0; j < 10; ++j) {
                if(freq[j] == 0) continue;
                int num = (freq[j] % 2 != 0) ? 0 : (1 << j);
                for(int k = 0; k < 10; ++k) {
                    if(j == k) continue;
                    if(freq[k] % 2 != 0) {
                        num |= (1 << k);
                    }
                }
                // cout << i << " " << num << " " << endl;
                ans += mp[num];
            }
            int num2 = 0;
            for(int j = 0; j < 10; ++j) {
                if(freq[j] % 2 != 0) num2 |= (1 << j);
            }
            // cout << i << " " << num2 << endl;
            ans += mp[num2];
            mp[num2]++;
        }
        return ans;
    }
};