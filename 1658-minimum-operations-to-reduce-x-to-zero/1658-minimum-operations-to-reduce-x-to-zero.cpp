class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totSum = 0;
        for(int ele : nums) totSum += ele;
        if(x > totSum) return -1;
        int mx = -1e9, i = 0, sum = 0;
        for(int j = 0; j < nums.size(); ++j) {
            sum += nums[j];
            while(sum > (totSum - x)) {
                sum -= nums[i++];
            }
            if(sum == totSum - x) {
                mx = max(mx, j - i + 1);
            }
        }
        if(mx == -1e9) return -1;
        return nums.size() - mx;
    }
};