class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        map<int, int> prev;
        long long ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            map<int, int> curr;
            ans += (nums[i] == k);
            curr[nums[i]]++;
            for(auto &ele : prev) {
                if((ele.first & nums[i]) == k) {
                    ans += ele.second;
                } 
                curr[(nums[i] & ele.first)] += ele.second;
            }
            prev = curr;
        }
        return ans;
    }
};