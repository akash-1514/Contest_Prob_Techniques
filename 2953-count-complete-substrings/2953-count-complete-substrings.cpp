class Solution {
public:
    int countSubstring(string &word, int k, int len) {
        int ans = 0, cnt = 0;
        unordered_map<char, int>mp;
        int i = 0, j = 0;
        while(j < word.size()) {
            if(i == j) {
                if(mp[word[j]] == k) cnt--;
                if(++mp[word[j]] == k) cnt++;
            } else {
                if(abs(word[j] - word[j - 1]) > 2) {
                    cnt = 0;
                    while(i < j) {
                        if(--mp[word[i]] == 0) mp.erase(word[i]);
                        i++;
                    }
                    if(mp[word[j]] == k) cnt--;
                    if(++mp[word[j]] == k) cnt++;
                } else {
                    if(mp[word[j]] == k) cnt--;
                    if(++mp[word[j]] == k) cnt++;
                }
            }
            
            if(j - i + 1 == len) {
                if(mp.size() == cnt) ans++;
            } else if(j - i + 1 > len) {
                while(j - i + 1 > len) {
                    if(mp[word[i]] == k) cnt--;
                    if(--mp[word[i]] == k) cnt++;
                    if(mp[word[i]] == 0) mp.erase(word[i]);
                    i++;
                }
                if(mp.size() == cnt) ans++;
            }
            j++;
        }
        return ans;
    }
    int countCompleteSubstrings(string word, int k) {
        int ans = 0, n = word.size();
        for(int i = k; i <= word.size() && i / k <= 26; i += k) {
            int res = countSubstring(word, k, i);
            ans += res;
        }
        return ans;
    }
};