class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool found = false, inc = false;
        for(int i = 1; i < n; ++i) {
            if(nums[i] == nums[i - 1]) continue;
            if(nums[i] < nums[i - 1]) {
                if(!found) {
                    inc = false;
                    found = true;
                } else {
                    if(inc) return false;
                }
            } else {
                if(!found) {
                    inc = true, found = true;
                } else {
                    if(!inc) return false;
                }
            }
        }
        return true;
    }
};