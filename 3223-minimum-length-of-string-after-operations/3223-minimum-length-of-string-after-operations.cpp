class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        unordered_map<char, int>mp;
        int ans = n;
        for(int i = 0; i < n; ++i) {
            mp[s[i]]++;
            if(mp[s[i]] == 3) {
                mp[s[i]] -= 2;
                ans -= 2;
            } 
        }
        return ans;
    }
};