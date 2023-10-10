class Solution {
public:
    int dp[101];
    int helper(vector<int>&arr, int idx) {
        if(idx == arr.size()) {
            return 0;
        }
        
        if(dp[idx] != -1) return dp[idx];
        
        int pick = arr[idx];
        if(idx + 2 < arr.size()) {
            pick += helper(arr, idx + 2);
        }
        int notPick = helper(arr, idx + 1);
        
        return dp[idx] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, 0);
    }
};