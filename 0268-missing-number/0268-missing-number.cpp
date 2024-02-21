class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n * 1ll * (n + 1)) / 2;
        int totSum = 0;
        for(int ele : nums) totSum += ele;
        return sum - totSum;
    }
};