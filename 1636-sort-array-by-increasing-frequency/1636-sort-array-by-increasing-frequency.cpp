class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(int ele : nums) mp[ele]++;
        sort(nums.begin(), nums.end(), [&](int x, int y) {
            if(mp[x] == mp[y]) {
                return x > y;
            }
            return mp[x] < mp[y];
        });
        return nums;
    }
};