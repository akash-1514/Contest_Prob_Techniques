class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mp;
        for(int ele : nums1) mp[ele]++;
        vector<int>ans;
        for(int ele : nums2) {
            if(mp[ele] > 0) {
                ans.push_back(ele);
                mp[ele]--;
            }
        }
        return ans;
    }
};