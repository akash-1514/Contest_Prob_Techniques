class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long mx = -1, sum = nums[0] + nums[1];
        for(int i = 2; i < n; ++i) {
            if(sum > nums[i]) {
                mx = max(mx, sum + nums[i]);
            }
            sum += nums[i];
        }
        return mx; 
    }
};