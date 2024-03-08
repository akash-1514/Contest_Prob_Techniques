class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(int ele : nums) mp[ele]++;
        int mx = 0;
        for(auto &it : mp) mx = max(mx, it.second);
        int ans = 0;
        for(auto &it : mp) {
            if(it.second == mx) {
                ans += it.second;
            }
        }
        return ans;
    }
};