class Solution {
public:
    bool pred(int n, vector<int>&batteries, long long time) {
        long long sum = 0;
        for(int ele : batteries) {
            sum += (ele >= time) ? time : ele;
        }
        return (sum / n) >= time;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 1, high = 1e15, ans = 1;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(pred(n, batteries, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};