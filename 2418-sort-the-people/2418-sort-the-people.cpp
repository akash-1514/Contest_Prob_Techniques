class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> vec;
        for(int i = 0; i < n; ++i) {
            vec.push_back({heights[i], names[i]});
        }
        
        sort(vec.begin(), vec.end());
        
        vector<string>ans;
        for(int i = vec.size() - 1; i >= 0; --i) {
            ans.push_back(vec[i].second);
        }
        return ans;
    }
};