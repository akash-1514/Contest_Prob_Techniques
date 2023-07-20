class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<int>&nums, int idx, int k) {
        if(idx >= nums.size()) {
            if(k == 0) return 1;
            return 0;
        }
        if(dp[idx][k] != -1) return dp[idx][k];
        int cnt = 0;
        if(nums[idx] <= k) {
            cnt += helper(nums, idx + 1, k - nums[idx]);
        }
        cnt += helper(nums, idx + 1, k);
        return dp[idx][k] = cnt;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int tot = 0;
        for(int ele : nums) tot += ele;
        
        if(tot - target < 0 || (tot - target) % 2 != 0) return 0;
        int k = (tot - target) / 2;
        dp.resize(nums.size(), vector<int>(k + 1, -1));
        return helper(nums, 0, k);
    }
};