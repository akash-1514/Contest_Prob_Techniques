class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int>mp;
        for(auto &p : paths) {
            mp[p[0]]++;
        }
        
        for(auto &p : paths) {
            if(mp[p[0]] == 0) return p[0];
            if(mp[p[1]] == 0) return p[1];
        }
        
        return "";
    }
};