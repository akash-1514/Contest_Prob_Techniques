class Solution {
public:
    vector<int> NSR(vector<int>&arr) {
        int n = arr.size();
        stack<int>st;
        vector<int>ans;
        for(int i = n - 1; i >= 0; --i) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
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
    long long maximumSumOfHeights(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsl = NSL(arr);
        vector<int> nsr = NSR(arr);
        
        vector<long long> prefix(n, 0), suffix(n, 0);
        prefix[0] = arr[0], suffix[n - 1] = arr[n - 1];
        
        for(int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + arr[i];
            suffix[n - i - 1] = suffix[n - i] + arr[n - i - 1];
        }
        
        vector<pair<long, long>> pre(n);
        for(int i = 0; i < n; ++i) {
            long long idx = nsl[i], ele = i - idx - 1;
            long long totSum = ele * arr[i];
            
            long long rangeSum = 0;
            if(idx == -1) {
                rangeSum += (i > 0 ? prefix[i - 1] : 0);
            } else {
                rangeSum += prefix[i - 1] - prefix[idx];
            }
            
            if(idx == -1) {
                pre[i].first = rangeSum - totSum;
            } else {
                pre[i].first = (rangeSum - totSum) + pre[idx].first;
            }
        }
        
        for(int i = n - 1; i >= 0; --i) {
            long long idx = nsr[i], ele = idx - i - 1;
            long long totSum = ele * arr[i];
            
            long long rangeSum = 0;
            if(idx == n) {
                rangeSum += ((i < n - 1) ? suffix[i + 1] : 0);
            } else {
                rangeSum += suffix[i + 1] - suffix[idx];
            }
            
            if(idx == n) {
                pre[i].second = rangeSum - totSum;
            } else {
                pre[i].second = (rangeSum - totSum) + pre[idx].second;
            }
        }
        
        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            long long sum = arr[i] + (i > 0 ? prefix[i - 1] : 0) + (i < n - 1 ? suffix[i + 1] : 0) - pre[i].first - pre[i].second;
            
            ans = max(ans, sum);
        }
        return ans;
    }
};