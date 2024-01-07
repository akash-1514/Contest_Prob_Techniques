class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_set<int> st1, st2;
        for(int i = 0; i < n; ++i) {
            st1.insert(nums1[i]);
            st2.insert(nums2[i]);
        }
        
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for(int ele : st1) {
            if(st2.count(ele)) {
                cnt1++;
            } else {
                cnt2++;
            }
        }
        
        for(int ele : st2) {
            if(!st1.count(ele)) {
                cnt3++;
            }
        }
        
        return min(min(cnt2, n / 2) + min(cnt3, n / 2) + cnt1, n);
    }
};