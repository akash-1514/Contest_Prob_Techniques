class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0;
        long long sum = 0;
        for(int i = 0; i < nums.size() && sum < n;) {
            if(sum + 1 >= nums[i]) {
                sum += nums[i];
                i++;
            } else {
                ans++;
                sum += (sum + 1);
            }
        }
        while(sum < n) {
            ans++;
            sum += (sum + 1);
        }
        return ans;
    }
};