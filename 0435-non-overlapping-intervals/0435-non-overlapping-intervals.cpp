class Solution {
public:
    int dp[100001];
    int helper(vector<vector<int>>&arr, int idx) {
        if(idx >= arr.size()) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        vector<int>v = {arr[idx][1], INT_MIN};
        auto nextIdx = lower_bound(arr.begin(), arr.end(), v) - arr.begin();
        
        int pick = 1 + helper(arr, nextIdx);
        int notPick = helper(arr, idx + 1);
        return dp[idx] = max(pick, notPick);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        memset(dp, -1, sizeof(dp));
        sort(intervals.begin(), intervals.end());
        return n - helper(intervals, 0);
    }
};