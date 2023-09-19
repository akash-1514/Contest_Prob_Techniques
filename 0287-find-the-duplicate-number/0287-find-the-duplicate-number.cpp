class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // cyclic sort
        int n = nums.size(), i = 0;
        while(i < n) {
            int correctIdx = nums[i] - 1;
            if(nums[correctIdx] != nums[i]) {
                swap(nums[correctIdx], nums[i]);
            } else {
                i++;
            }
        }
        for(int i = 0; i < n; ++i) {
            if(nums[i] != i + 1) {
                return nums[i];
            }
        }
        return -1;
    }
};