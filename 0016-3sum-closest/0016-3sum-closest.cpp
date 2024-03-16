class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int diff = 1e9, ans = 0;
        for(int i = 0; i < n; ++i) {
            int start = i + 1, end = n - 1;
            int req = target - nums[i];
            while(start < end) {
                int currSum = nums[start] + nums[end];
                int totSum = nums[i] + nums[start] + nums[end];
                if(abs(target - totSum) < diff) {
                    diff = abs(target - totSum);
                    ans = totSum;
                }
                if(currSum == req) {
                    start++, end--;
                    while(start < end && nums[start] == nums[start - 1]) start++;
                    while(start < end && nums[end] == nums[end + 1]) end--;
                } else if(currSum > req) {
                    end--;
                } else {
                    start++;
                }
            }
            while(i < n - 1 && nums[i] == nums[i + 1]) i++;
        }
        
        return ans;
    }
};