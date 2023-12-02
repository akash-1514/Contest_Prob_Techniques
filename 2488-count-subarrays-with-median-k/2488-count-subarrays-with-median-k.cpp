class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mp;
        int sum = 0, ans = 0;
        bool found = false;
        mp[0] = 1;
        for(int i = 0; i < n; ++i) {
            if(nums[i] < k) {
                sum--;
            } else if(nums[i] > k) {
                sum++;
            } else {
                found = true;
            }
            
            if(found) {
                ans += mp[sum] + mp[sum - 1];
            } else {
                mp[sum]++;
            }
        }
        return ans;
    }
};