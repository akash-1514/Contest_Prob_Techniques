class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return false;
        for(int i = 0; i < n - 2; ++i) {
            int p1 = (nums[i] & 1), p2 = (nums[i + 1] & 1), p3 = (nums[i + 2] & 1);
            if(p1 == 1 && p1 == p2 && p2 == p3) {
                return true;
            }
        }
        return false;
    }
};