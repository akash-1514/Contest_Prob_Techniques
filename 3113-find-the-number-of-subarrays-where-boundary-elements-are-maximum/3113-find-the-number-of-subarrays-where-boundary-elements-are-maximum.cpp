class Solution {
public:
    vector<int> NGR(vector<int>&arr) {
        int n = arr.size();
        stack<int>st;
        vector<int>ans;
        for(int i = n - 1; i >= 0; --i) {
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if(st.empty()) {
                ans.push_back(n);
            } else {
                ans.push_back(st.top());
            }
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    long long numberOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, vector<int>>mp;
        for(int i = 0; i < n; ++i) {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> ngr = NGR(nums);
        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            int r = ngr[i];
            int right = lower_bound(mp[nums[i]].begin(), mp[nums[i]].end(), r) - mp[nums[i]].begin();
            int left = lower_bound(mp[nums[i]].begin(), mp[nums[i]].end(), i) - mp[nums[i]].begin();
            ans += (right - left);
        }
        return ans;
    }
}; 