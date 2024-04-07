#define ll long long
class Solution {
public:
    bool check(int n, vector<ll>&power, ll mid, int r, int k) {
        vector<ll> diff(n + 2, 0);
        for(int i = 0; i < n; ++i) {
            diff[i] += ((i > 0) ? diff[i - 1] : 0);
            ll sum = power[i] + diff[i];
            if(sum < mid) {
                ll req = mid - sum;
                if(req > k) return false;
                k -= req;
                diff[i] += req;
                diff[min(n - 1, i + 2 * r) + 1] -= req;
            } 
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<ll> power(n + 2, 0);
        for(int i = 0; i < n; ++i) {
            power[max(0, i - r)] += stations[i];
            power[min(n - 1, i + r) + 1] -= stations[i];
        }
        for(int i = 1; i < n; ++i) {
            power[i] += power[i - 1];
        }
        ll low = 0, high = 1e15, ans = 0;
        while(low <= high) {
            ll mid = (low + high) / 2;
            if(check(n, power, mid, r, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};