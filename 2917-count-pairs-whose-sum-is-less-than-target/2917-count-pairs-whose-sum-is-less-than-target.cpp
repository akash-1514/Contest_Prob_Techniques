class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int i = 0, j = nums.size() - 1;
        while(i < j) {
            int sum = nums[i] + nums[j];
            if(sum >= target) {
                j--;
            } else {
                cnt += (j - i);
                i++;
            }
        }

        return cnt;
    }
};