class Solution {
public:
    int dp[301][301];
    int helper(vector<int>&nums, int i, int j) {
        if(i == j) {
            return nums[i - 1] * nums[i] * nums[i + 1];
        }
        
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int maxCoin = 0;
        for(int k = i; k <= j; ++k) {
            maxCoin = max(maxCoin, nums[i - 1] * nums[k] * nums[j + 1] + helper(nums, i, k - 1) + helper(nums, k + 1, j));
        }
        return dp[i][j] = maxCoin;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        memset(dp, -1, sizeof(dp));
        return helper(nums, 1, nums.size() - 2);
    }
};