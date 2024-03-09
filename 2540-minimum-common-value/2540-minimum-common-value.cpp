class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0;
        while(i < n1 && j < n2) {
            if(nums1[i] < nums2[j]) {
                i++;
            } else if(nums2[j] < nums1[i]) {
                j++;
            } else {
                return nums1[i];
            }
        }
        return -1;
    }
};