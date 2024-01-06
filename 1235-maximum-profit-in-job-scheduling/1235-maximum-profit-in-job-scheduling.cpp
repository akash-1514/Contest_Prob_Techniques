class Solution {
public:
    int dp[50001];
    int helper(vector<vector<int>>&arr, int idx) {
        if(idx >= arr.size()) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int maxProfit = 0;
        
        vector<int> v = {arr[idx][1], INT_MIN, INT_MIN};
        auto i = lower_bound(arr.begin(), arr.end(), v) - arr.begin();
        
        maxProfit = max(maxProfit, arr[idx][2] + helper(arr, i));
        maxProfit = max(maxProfit, helper(arr, idx + 1));
        
        return dp[idx] = maxProfit;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>vec;
        for(int i = 0; i < n; ++i) {
            vec.push_back({startTime[i], endTime[i], profit[i]});
        }
        memset(dp, -1, sizeof(dp));
        sort(vec.begin(), vec.end());
        return helper(vec, 0);
    }
};