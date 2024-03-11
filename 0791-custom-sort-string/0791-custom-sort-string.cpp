class Solution {
public:
    string customSortString(string order, string s) {
        int n = s.size();
        unordered_map<char, int>mp;
        for(int i = 0; i < order.size(); ++i) {
            mp[order[i]] = i + 1;
        }
        
        vector<pair<int, char>>vec;
        for(int i = 0; i < s.size(); ++i) {
            if(mp[s[i]] != 0) {
                vec.push_back({mp[s[i]], s[i]});
            }
        }
        
        sort(vec.begin(), vec.end());
        int idx = 0;
        for(int i = 0; i < n; ++i) {
            if(mp[s[i]] != 0) {
                s[i] = vec[idx].second;
                idx++;
            }
        }
        
        return s;
    }
};