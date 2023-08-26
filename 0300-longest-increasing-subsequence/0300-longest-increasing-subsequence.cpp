class Solution {
public:
    int dp[2501][2505];
    int helper(vector<int>&nums, int idx, int prev) {
        if(idx >= nums.size()) return 0;
        
        if(dp[idx][prev + 1] != -1) return dp[idx][prev + 1];
        
        int mx = 0;
        if(prev == -1) {
            mx = max(mx, 1 + helper(nums, idx + 1, idx));
        } else if(nums[idx] > nums[prev]) {
            mx = max(mx, 1 + helper(nums, idx + 1, idx));
        }
        mx = max(mx, helper(nums, idx + 1, prev));
        return dp[idx][prev + 1] = mx;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, 0, -1);
    }
};