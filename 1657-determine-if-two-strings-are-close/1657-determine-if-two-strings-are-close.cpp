class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int>mp1, mp2;
        unordered_map<int, int>mp3;
        int cnt = 0;
        for(char ch : word1) mp1[ch]++;
        for(char ch : word2) {
            mp2[ch]++;
        }
        
        for(auto &it : mp2) {
            if(mp1.find(it.first) != mp1.end()) {
                cnt++;
            }
        }
        
        if(cnt != mp1.size()) return false;
            
        for(auto &it : mp1) mp3[it.second]++;
        for(auto &it : mp2) {
            if(--mp3[it.second] == 0) mp3.erase(it.second);
        }
        return mp3.size() == 0;
    }
};