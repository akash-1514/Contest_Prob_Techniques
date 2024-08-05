class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int>mp;
        for(auto &str : arr) {
            mp[str]++;
        }
        
        int cnt = 0;
        
        for(auto &str : arr) {
            if(mp[str] == 1) {
                if(++cnt == k) return str;
            }
        }
        
        return "";
    }
};