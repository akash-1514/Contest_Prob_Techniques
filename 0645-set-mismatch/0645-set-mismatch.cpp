class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // 1 to n
        // cyclic sort
        int i = 0;
        while(i < nums.size()) {
            int correctIdx = nums[i] - 1;
            if(nums[correctIdx] != nums[i]) {
                swap(nums[i], nums[correctIdx]);
            } else {
                i++;
            }
        }

        vector<int>ans;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != i + 1) {
                return {nums[i], i + 1};
            }
        }
        return {};
    }
};