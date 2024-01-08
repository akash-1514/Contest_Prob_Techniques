class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        if(n <= 2) return 0;
        vector<int>dp(n, 0);
        dp[0] = 0, dp[1];
        int prevDiff = nums[1] - nums[0];
        for(int i = 2; i < n; ++i) {
            int currDiff = nums[i] - nums[i - 1];
            if(currDiff == prevDiff) {
                dp[i] = dp[i - 1] + 1;
            }
            prevDiff = currDiff;
            ans += dp[i];
        }
        return ans;
    }
};