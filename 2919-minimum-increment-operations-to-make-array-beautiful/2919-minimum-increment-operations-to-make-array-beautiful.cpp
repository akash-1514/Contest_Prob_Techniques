class Solution {
public:
    long long dp[100001];
    long long helper(vector<int>&nums, int idx, int k) {
        // base case
        
        if(idx >= nums.size() - 2) {
            return 0;
        }
        
        if(dp[idx] != -1) return dp[idx];
        
        long long ans = LONG_MAX;
        for(int i = idx; i < min((int)nums.size(), idx + 3); ++i) {
            long long val = max(0, k - nums[i]) + helper(nums, i + 1, k);
            ans = min(ans, val);
        }
        
        return dp[idx] = ans;
    }
    long long minIncrementOperations(vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, 0, k);
    }
};