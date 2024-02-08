#define ll long long
class Solution {
public:
    bool pred(ll num, ll k, int x) {
        vector<long long> ans(64, 0);
        while(num) { 
            if(num == 1) {
                ans[0]++; break;
            } else if(num == 2) {
                ans[0]++, ans[1]++; break;
            } else {
                ll maxSetBit = log2(num);
                ll val = (1ll << maxSetBit);
                ans[maxSetBit] += num - val + 1;
                for(int i = maxSetBit - 1; i >= 0; --i) {
                    ans[i] += (val / 2);
                }
                num -= val;
            }
        }
        
        ll price = 0;
        for(int i = 0; i < 64; ++i) {
            if((i + 1) % x == 0) {
                price += ans[i];
            }
        }
        return price <= k;
    }
    long long findMaximumNumber(long long k, int x) {
        ll low = 1, high = 1e16, ans = 1;
        while(low <= high) {
            ll mid = (low + high) >> 1; // (low + high) / 2
            if(pred(mid, k, x)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};