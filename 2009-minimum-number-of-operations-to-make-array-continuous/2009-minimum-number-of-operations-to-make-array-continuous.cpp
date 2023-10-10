class Solution {
public:
    int minOperations(vector<int>& arr) {
        int n = arr.size();
        set<int>st;
        for(int ele : arr) st.insert(ele);
        vector<int>nums;
        for(auto &it : st) {
            nums.push_back(it);
        }
        int mn = 1e9;
        for(int i = 0; i < nums.size(); ++i) {
            auto idx = upper_bound(nums.begin(), nums.end(), nums[i] + n - 1) - nums.begin();
            int missing = n - (idx - i);
            mn = min(mn, missing);
        }
        return mn;
    }
};