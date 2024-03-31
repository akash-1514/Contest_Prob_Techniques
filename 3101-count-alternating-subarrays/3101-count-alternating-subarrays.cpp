class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        long long ans = 0;
        while(j < n) {
            if(i != j) {
                if(nums[j] == nums[j - 1]) {
                    i = j;
                    ans += 1;
                } else {
                    ans += (j - i + 1);
                }
            } else {
                ans += 1;
            }
            j++;
        }
        return ans;
    }
};