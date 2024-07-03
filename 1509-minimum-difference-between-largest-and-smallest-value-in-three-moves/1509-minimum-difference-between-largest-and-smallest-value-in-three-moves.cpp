class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4) return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for(int i = 0; i < n; ++i) {
            if(n + i - 4 < n) {
                ans = min(ans, nums[n + i - 4] - nums[i]);
            } else {
                break;
            }
        }
        return ans;
    }
};