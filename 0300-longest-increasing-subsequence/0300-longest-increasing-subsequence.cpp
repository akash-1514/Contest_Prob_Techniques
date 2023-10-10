class Solution {
public:
    int dp[2502][2502];
    int helper(vector<int>&arr, int idx, int prev) {
        if(idx > arr.size()) return 0;
        
        if(dp[idx][prev] != -1) return dp[idx][prev];
        
        int mx = 0;
        if(prev == 0) {
            mx = max({mx, 1 + helper(arr, idx + 1, idx), helper(arr, idx + 1, prev)});
        } else {
            if(arr[idx - 1] > arr[prev - 1]) {
                mx = max({mx, 1 + helper(arr, idx + 1, idx), helper(arr, idx + 1, prev)});
            } else {
                mx = max(mx, helper(arr, idx + 1, prev));
            }
        }
        return dp[idx][prev] = mx;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, 1, 0);
    }
};