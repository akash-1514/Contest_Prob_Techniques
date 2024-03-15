class Solution {
public:
    int countSubstring(string &s, int x, int k) {
        if(x * k == 1) return s.size();
        unordered_map<char, int>mp;
        int i = 0, cnt = 0, ans = 0;
        mp[s[0]]++;
        if(mp[s[0]] == k) cnt++;
        for(int j = 1; j < s.size(); ++j) {
            if(abs(s[j] - s[j - 1]) > 2) {
                while(i < j) {
                    if(mp[s[i]] == k) cnt--;
                    if(--mp[s[i]] == k) cnt++;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }
                mp[s[j]]++;
                if(mp[s[j]] == k) cnt++;
            } else {
                if(mp[s[j]] == k) cnt--;
                if(++mp[s[j]] == k) cnt++;
            }
            
            if(j - i + 1 == x * k) {
                if(cnt == mp.size()) {
                    ans++;
                }
            } else if(j - i + 1 > x * k) {
                if(mp[s[i]] == k) cnt--;
                if(--mp[s[i]] == k) cnt++;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
                if(cnt == mp.size()) {
                    ans++;
                }
            }
        }
        return ans;
    }
    int countCompleteSubstrings(string word, int k) {
        int n = word.size();
        int ans = 0;
        for(int i = 1; i <= 26 && i * k <= n; ++i) {
            ans += countSubstring(word, i, k);
        }
        return ans;
    }
};