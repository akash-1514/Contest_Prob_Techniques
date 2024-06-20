class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, int> mp;
        unordered_map<int, int> sum;
        
        mp[0] = 1;
        sum[0] = -1;
        
        int ans = 0, xorr = 0;
        for(int i = 0; i < n; ++i) {
            xorr ^= arr[i];
            if(mp.find(xorr) != mp.end()) {
                ans += (mp[xorr] * (i - 1) - sum[xorr]);
            }
            mp[xorr]++;
            sum[xorr] += i;
        }
        return ans;
    }
};