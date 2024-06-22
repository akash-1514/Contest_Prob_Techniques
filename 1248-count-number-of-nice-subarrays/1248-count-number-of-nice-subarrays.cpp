class Solution {
public:
    int atmostK(vector<int>&nums, int k) {
        int i = 0, n = nums.size(), cnt = 0, ans = 0;
        for(int j = 0; j < n; ++j) {
            if(nums[j] & 1) cnt++;
            while(cnt > k) {
                if(nums[i] & 1) cnt--;
                i++;
            }
            ans += (j - i + 1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostK(nums, k) - atmostK(nums, k - 1);
    }
};