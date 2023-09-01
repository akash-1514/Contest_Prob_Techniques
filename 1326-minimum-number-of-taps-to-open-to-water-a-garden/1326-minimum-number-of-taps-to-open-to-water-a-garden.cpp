class Solution {
public:
    map<pair<int, int>, int>dp;
    int helper(vector<pair<int, int>>&vec, int idx, int maxEnd) {
        if(maxEnd == vec.size() - 1) return 0;
        if(idx >= vec.size()) return 1e9;
        if(vec[idx].first > maxEnd) return 1e9;
        
        if(dp.find({idx, maxEnd}) != dp.end()) return dp[{idx, maxEnd}];
        
        int take = 1e9;
        if(vec[idx].first <= maxEnd) {
            take = 1 + helper(vec, idx + 1, (int)max(maxEnd, vec[idx].second));
        }
        
        int notTake = helper(vec, idx + 1, maxEnd);
        
        return dp[{idx, maxEnd}] = min(take, notTake);
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>>vec;
        int idx = 0;
        for(auto &rang : ranges) {
            int l = max(0, idx - rang);
            int r = min(n, idx + rang);
            vec.push_back({l, r});
            idx++;
        }
        sort(vec.begin(), vec.end());
        int res = helper(vec, 0, 0);
        return res == 1e9 ? -1 : res;
    }
};