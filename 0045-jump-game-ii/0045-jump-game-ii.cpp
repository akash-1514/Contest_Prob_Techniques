class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach = 0, currReach = 0, jumps = 0;
        for(int i = 0; i < nums.size() - 1; ++i) {
            currReach = max(currReach, i + nums[i]);
            if(i == maxReach) {
                jumps++;
                maxReach = currReach;
            }
        }
        if(maxReach < nums.size() - 1) return -1;
        return jumps;
    }
};