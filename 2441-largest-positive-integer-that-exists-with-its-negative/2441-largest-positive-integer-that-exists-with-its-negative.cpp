class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int>mp;
        int mx = -1;
        for(int ele : nums) {
            if(mp.find(-1 * ele) != mp.end()) {
                mx = max(mx, abs(ele));
            }
            mp[ele]++;
        }
        return mx;
    }
};