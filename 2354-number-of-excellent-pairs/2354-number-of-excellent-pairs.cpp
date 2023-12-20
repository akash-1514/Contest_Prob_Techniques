class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> vec;
        unordered_map<int, int>mp;
        for(int i = 0; i < n; ++i) {
            if(mp.find(nums[i]) != mp.end()) continue;
            int set_bits = __builtin_popcount(nums[i]);
            vec.push_back(set_bits);
            mp[nums[i]]++;
        }
        for(int ele : vec) cout << ele << " ";
        cout << endl;
        long long ans = 0;
        sort(vec.begin(), vec.end());
        for(int i = 0; i < vec.size(); ++i) {
            int idx = lower_bound(vec.begin() + i, vec.end(), k - vec[i]) - vec.begin();
            ans += 2 * (vec.size() - idx);
        }
        
        unordered_map<int, int>mp2;
        for(int ele : nums) mp2[ele]++;
        
        for(auto &it : mp2) {
            int sb = __builtin_popcount(it.first);
            if(it.second >= 1 && 2 * sb >= k) ans--;
        }
        
        return ans;
    }
};