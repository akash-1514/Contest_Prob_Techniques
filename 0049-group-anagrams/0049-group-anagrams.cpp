class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string, vector<string>>mp;
        for(auto &str : strs) {
            string dup = str;
            sort(dup.begin(), dup.end());
            mp[dup].push_back(str);
        }
        
        for(auto &it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};