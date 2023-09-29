class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool found = false, inc = false;
        for(int i = 1; i < n; ++i) {
            if(nums[i] == nums[i - 1]) continue;
            if(found) {
                if(inc) {
                    if(nums[i] < nums[i - 1]) return false;
                } else {
                    if(nums[i] > nums[i - 1]) return false;
                }
            } else {
                if(nums[i] > nums[i - 1]) {
                    inc = true;
                } 
                found = true;
            }
        }
        return true;
    }
};