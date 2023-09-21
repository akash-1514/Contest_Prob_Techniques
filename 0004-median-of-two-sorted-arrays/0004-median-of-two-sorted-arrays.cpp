class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        for(int ele : nums1) vec.push_back(ele); 
        for(int ele : nums2) vec.push_back(ele);
        sort(vec.begin(), vec.end());
        if(vec.size() % 2 != 0) {
            return vec[vec.size() / 2];
        } else {
            double res = vec[vec.size() / 2] + vec[(vec.size() / 2) - 1];
            return res / 2;
        }
    }
};