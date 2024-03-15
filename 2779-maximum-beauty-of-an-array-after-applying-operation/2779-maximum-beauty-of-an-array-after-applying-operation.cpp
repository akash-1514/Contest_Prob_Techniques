class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int, int>mp;
        for(int ele : nums) {
            mp[ele - k]++;
            mp[ele + k + 1]--;
        }
        
        int mx = 0, cnt = 0;
        for(auto &it : mp) {
            cnt += it.second;
            mx = max(mx, cnt);
        }
        return mx;
    }
};