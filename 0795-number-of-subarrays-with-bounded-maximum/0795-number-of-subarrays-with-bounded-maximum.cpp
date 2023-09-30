class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        vector<int> dp(n, 0);
        int mx = nums[0] > right ? 0 : -1;
        dp[0] = (nums[0] >= left && nums[0] <= right);
        for(int i = 1; i < n; ++i) {
            if(nums[i] > right) {
                mx = i;
            } else {
                if(nums[i] < left) dp[i] = dp[i - 1];
                else dp[i] = i - mx;
            }
        }
        
        int sum = 0;
        for(int ele : dp) {
            sum += ele;
        }
        
        return sum;
    }
};