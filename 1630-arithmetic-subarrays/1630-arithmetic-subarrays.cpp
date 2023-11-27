class Solution {
public:
    bool check(vector<int>&nums, int l, int r) {
        unordered_set<int>st;
        int mx = -1e9, mn = 1e9;
        for(int i = l; i <= r; ++i) {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
            st.insert(nums[i]);
        }
        
        if(((mx - mn) % (r - l)) != 0) return false;
        
        int d = (mx - mn) / (r - l);
        
        int curr = mn;
        while(curr < mx) {
            if(st.find(curr) == st.end()) return false;
            curr += d;
        }
        
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool>ans(n);
        for(int i = 0; i < n; ++i) {
            if(check(nums, l[i], r[i])) {
                ans[i] = true;
            } else {
                ans[i] = false;
            }
        }
        return ans;
    }
};