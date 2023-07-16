class Solution {
public:
    int mod = 1e9 + 7;
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
            while(!st.empty() && arr[st.top()] > arr[i]) {
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
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ngl = NSL(arr);
        vector<int> ngr = NSR(arr);
        
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int left = i - ngl[i], right = ngr[i] - i;
            ans = (ans + left * 1ll * right * 1ll * arr[i]) % mod;
        }
        
        return ans;
    }
};