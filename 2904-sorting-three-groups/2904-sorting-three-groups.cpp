class Solution {
public:
    int dp[101][4];
    int helper(vector<int>&nums, int idx, int prev) {
        if(idx >= nums.size()) return 0;
        
        if(dp[idx][prev] != -1) return dp[idx][prev];

        int mn = 1e9;
        for(int i = (prev == 0) ? 1 : prev; i <= 3; ++i) {
            if(nums[idx] == i) {
                mn = min(mn, helper(nums, idx + 1, nums[idx]));
            } else {
                mn = min(mn, 1 + helper(nums, idx + 1, i));
            }
        }
        return dp[idx][prev] = mn;
    }
    int minimumOperations(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, 0, 0);
    }
};