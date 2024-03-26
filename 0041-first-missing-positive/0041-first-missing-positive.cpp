class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0, n = nums.size();
        while(i < n) {
            long long correctIdx = (long long)nums[i] - 1;
            if(nums[i] <= 0 || nums[i] >= n || nums[correctIdx] == nums[i]) {
                i++;
            } else {
                swap(nums[i], nums[correctIdx]);
            }
        }
        
        for(int i = 0; i < n; ++i) {
            if(nums[i] != (i + 1)) {
                return (i + 1);
            }
        }
        
        return n + 1;
    }
};