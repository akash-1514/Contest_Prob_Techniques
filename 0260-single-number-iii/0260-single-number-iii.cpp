class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 2) return nums;
        int x = 0;
        for(int ele : nums) x ^= ele;
        
        int idx = 0;
        for(int i = 0; i < 32; ++i) {
            if((x & (1 << i)) != 0) {
                idx = i;
                break;
            }
        }
        
        int val = (1 << idx);
        
        int a = 0, b = 0;
        for(int ele : nums) {
            if((val & ele) == 0) {
                a ^= ele;
            } else {
                b ^= ele;
            }
        }
        
        return {a, b};
    }
};