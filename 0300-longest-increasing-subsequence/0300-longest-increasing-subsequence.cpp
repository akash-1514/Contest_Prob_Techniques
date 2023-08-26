class Solution {
public:
    // int dp[2501][2505];
//     int helper(vector<int>&nums, int idx, int prev) {
//         if(idx >= nums.size()) return 0;
        
//         if(dp[idx][prev + 1] != -1) return dp[idx][prev + 1];
        
//         int mx = 0;
//         if(prev == -1) {
//             mx = max(mx, 1 + helper(nums, idx + 1, idx));
//         } else if(nums[idx] > nums[prev]) {
//             mx = max(mx, 1 + helper(nums, idx + 1, idx));
//         }
//         mx = max(mx, helper(nums, idx + 1, prev));
//         return dp[idx][prev + 1] = mx;
//     }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1);
        int mx = 1;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};