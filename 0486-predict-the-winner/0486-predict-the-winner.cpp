class Solution {
public:
    int dp[21][21];
    int helper(vector<int>&nums, int i, int j) {
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int pick1 = nums[i] + min(helper(nums, i + 2, j), helper(nums, i + 1, j - 1));
        int pick2 = nums[j] + min(helper(nums, i, j - 2), helper(nums, i + 1, j - 1));
        return dp[i][j] = max(pick1, pick2);
    }
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int player1_score = helper(nums, 0, nums.size() - 1);
        double tot = 0;
        for(int ele : nums) tot += ele;
        if(player1_score >= (1.0 * tot / 2)) return true;
        return false;
    }
};