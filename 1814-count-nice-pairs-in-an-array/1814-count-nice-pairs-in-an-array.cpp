class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x != 0) {
            int r = x % 10;
            rev = rev * 10 + r;
            x /= 10;
        }
        return rev;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int rev = reverse(nums[i]);
            ans = (ans + mp[nums[i] - rev]++) % 1000000007;
        }
        return ans;
    }
};