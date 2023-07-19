class Solution {
public:
    int dp[100001];
    int bs(vector<vector<int>>&inter, int x) {
        int low = 0, high = inter.size() - 1;
        int ans = inter.size();
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(inter[mid][0] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    int helper(vector<vector<int>>&intervals, int idx) {
        if(idx >= intervals.size()) {
            return 0;
        }
        
        if(dp[idx] != -1) return dp[idx];
        
        // vector<int>v = {intervals[idx][1], 0};
        // auto i = lower_bound(intervals.begin(), intervals.end(), v) - intervals.begin();
        
        auto i = bs(intervals, intervals[idx][1]);
        
        int mx = 0;
        mx = max(mx, 1 + helper(intervals, i));
        mx = max(mx, helper(intervals, idx + 1));
        return dp[idx] = mx;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        memset(dp, -1, sizeof(dp));
        return intervals.size() - helper(intervals, 0);
    }
};