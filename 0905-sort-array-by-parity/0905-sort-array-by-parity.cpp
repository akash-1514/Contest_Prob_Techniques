class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int o = 0, e = 0;
        while(e < nums.size()) {
            if(nums[e] % 2 != 0) e++;
            else {
                swap(nums[e], nums[o]);
                o++, e++;
            }
        }
        return nums;
    }
};