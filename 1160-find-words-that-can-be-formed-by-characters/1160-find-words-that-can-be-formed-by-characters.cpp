class Solution {
public:
    bool check(string &s, string &chars) {
        vector<int>freq(26, 0);
        for(char ch : s) freq[ch - 'a']++;
        for(char ch : chars) freq[ch - 'a']--;
        
        for(int i = 0; i < 26; ++i) {
            if(freq[i] > 0) return false;
        }
        
        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        for(auto &str : words) {
            if(check(str, chars)) {
                ans += str.size();
            }
        }
        return ans;
    }
};