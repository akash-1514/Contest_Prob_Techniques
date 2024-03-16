class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        set<vector<int>>st;
        for(int i = 0; i < n; ++i) {
            int start = i + 1, end = n - 1;
            int req = -1 * nums[i];
            while(start < end) {
                int currSum = nums[start] + nums[end];
                if(currSum == req) {
                    st.insert({nums[i], nums[start], nums[end]});
                    start++, end--;
                    while(start < end && nums[start] == nums[start - 1]) start++;
                    while(start < end && nums[end] == nums[end + 1]) end--;
                } else if(currSum > req) {
                    end--;
                } else {
                    start++;
                }
            }
        }
        
        for(auto &it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};