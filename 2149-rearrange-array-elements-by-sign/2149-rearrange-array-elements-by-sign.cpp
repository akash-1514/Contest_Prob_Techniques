class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, 0);
        int pos = 0, neg = 1, i = 0;
        while(i < n) {
            if(nums[i] > 0) {
                ans[pos] = nums[i];
                pos += 2; 
            } else {
                ans[neg] = nums[i];
                neg += 2;
            }
            i++;
        }
        return ans;
    }
};