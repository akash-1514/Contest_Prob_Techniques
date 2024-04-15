class Solution {
public:
    long long dp[20001][2];
    long long helper(vector<int>&nums, int idx, int cnt, int k) {
        if(idx >= nums.size()) {
            if(cnt == 0) return 0;
            return -1e9;
        }
        
        if(dp[idx][cnt] != -1) return dp[idx][cnt];
        
        long long mx = 0;
        
        mx = max(mx, (nums[idx] ^ k) + helper(nums, idx + 1, cnt ^ 1, k));
        mx = max(mx, nums[idx] + helper(nums, idx + 1, cnt, k));
        return dp[idx][cnt] = mx;
    }
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, 0, 0, k);
    }
};