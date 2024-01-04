class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int>mp;
        int ans = 0;
        for(int ele : nums) mp[ele]++;
        for(auto &it : mp) {
            int occ = it.second;
            if(occ == 1) return -1;
            if(occ % 3 == 0) {
                ans += occ / 3;
            } else { 
                ans += (occ / 3) + 1;
            }
        }
        return ans;
    }
};