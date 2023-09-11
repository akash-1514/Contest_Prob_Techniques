class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<pair<int, int>>vec;
        for(int i = 0; i < n; ++i) {
            vec.push_back({groupSizes[i], i});
        }
        
        sort(vec.begin(), vec.end());
        
        vector<vector<int>>ans;
        for(int i = 0; i < n;) {
            int cnt = vec[i].first;
            vector<int>g;
            while(i < n && cnt--) {
                g.push_back(vec[i].second);
                i++;
            }
            ans.push_back(g);
        }
        return ans;
    }
};