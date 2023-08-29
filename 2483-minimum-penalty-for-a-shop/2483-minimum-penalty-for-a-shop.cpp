class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int ans = 0, mn = 0;
        for(char ch : customers) mn += (ch == 'Y');
        vector<int> prefix(n, 0), suffix(n, 0);
        prefix[0] = (customers[0] == 'N'), suffix[n - 1] = 0;
        for(int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + (customers[i] == 'N');
            suffix[n - i - 1] = suffix[n - i] + (customers[n - i] == 'Y');
        }
        
        for(int i = 0; i < n; ++i) {
            int res = prefix[i] + suffix[i];
            if(res < mn) {
                mn = res;
                ans = i + 1;
            }
        }
        
        return ans;
    }
};