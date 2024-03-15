class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        long long i = 0, ans = 0;
        int cnt = 0;
        for(int j = 0; j < nums.size(); ++j) {
            if(nums[j] == mx) cnt++;
            while(cnt >= k) {
                ans += (nums.size() - j);
                if(nums[i] == mx) cnt--;
                i++;
            }
        }
        return ans;
    }
};