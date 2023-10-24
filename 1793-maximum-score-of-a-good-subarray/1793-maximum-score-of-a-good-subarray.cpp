
class Solution {
public:
    vector<int> NSR(vector<int>&arr) {
        int n = arr.size();
        stack<int>st;
        vector<int>ans;
        for(int i = n - 1; i >= 0; --i) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
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
    vector<int> NSL(vector<int>&arr) {
        int n = arr.size();
        stack<int>st;
        vector<int>ans;
        for(int i = 0; i < n; ++i) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if(st.empty()) {
                ans.push_back(-1);
            } else {
                ans.push_back(st.top());
            }
            st.push(i);
        }
        return ans;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nsr = NSR(nums);
        vector<int> nsl = NSL(nums);
        int ans = INT_MIN;
        for(int i = 0; i < n; ++i) {
            int l = nsl[i] + 1, r = nsr[i] - 1;
            if(k >= l && k <= r) {
                ans = max(ans, nums[i] * (r - l + 1));
            }
        }
        return ans;
    }
};