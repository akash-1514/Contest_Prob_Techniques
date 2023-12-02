class Solution {
public:
    bool check(string &s, string &chars) {
        unordered_map<char, int>mp;
        for(char ch : s) mp[ch]++;
        for(char ch : chars) mp[ch]--;
        
        for(auto &it : mp) {
            if(it.second > 0) return false;
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