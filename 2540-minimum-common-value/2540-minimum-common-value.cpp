class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        for(int i = 0; i < n1; ++i) {
            auto it = lower_bound(nums2.begin(), nums2.end(), nums1[i]);
            if(it != nums2.end()) {
                if(*it == nums1[i]) {
                    return nums1[i];
                }
            }
        }
        return -1;
    }
};