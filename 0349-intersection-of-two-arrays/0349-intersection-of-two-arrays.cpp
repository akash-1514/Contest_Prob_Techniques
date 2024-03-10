class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>mp1(1005, 0);
        
        for(int i = 0; i < nums1.size(); ++i)
        {
            mp1[nums1[i]]++;
        }
        
        vector<int>ans;
        
        for(int i = 0; i < nums2.size(); ++i)
        {
            if(mp1[nums2[i]] != 0)
            {
                ans.push_back(nums2[i]);
                mp1[nums2[i]] = 0;
            }
        }
        
        return ans;
    }
};