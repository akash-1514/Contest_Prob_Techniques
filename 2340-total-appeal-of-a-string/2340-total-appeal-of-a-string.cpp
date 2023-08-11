class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();
        long long tot = (n * 1ll * (n + 1)) / 2;
        long long ans = 0;
        for(char ch = 'a'; ch <= 'z'; ++ch) {
            long long res = 0;
            for(int i = 0; i < n; ++i) {
                if(s[i] != ch) {
                    int cnt = 0;
                    while(i < n && s[i] != ch) {
                        cnt++, i++;
                    }
                    res += (cnt * 1ll * (cnt + 1)) / 2;
                }
            }
            ans += (tot - res);
        }
        return ans;
    }
};