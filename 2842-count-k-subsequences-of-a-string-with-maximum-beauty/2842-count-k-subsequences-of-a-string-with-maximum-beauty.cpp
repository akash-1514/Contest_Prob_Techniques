class Solution {
public:
    int mod = 1000000007;
    const int N = 200005;
    long long binExpo(long long a, long long b, long long m) {
        if(b == 0) return 1;
        
        long long res = binExpo(a, b / 2, m);
        if(b % 2 == 0) {
            return (res * res) % m;
        } else {
            return ((a * res) % m * res) % m;
        }
    }
    
    long long modInverse(long long a, long long b, long long m) {
        return (a * binExpo(b, m - 2, m)) % mod;
    }
    
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        vector<long long> fact(N + 1, 0);
        fact[0] = fact[1] = 1;
        for(int i = 2; i <= N; ++i) {
            fact[i] = (fact[i - 1] * 1ll * i) % mod;
        }
        
        vector<int> freq(26, 0);
        for(char ch : s) {
            freq[ch - 'a']++;
        }
        
        sort(freq.begin(), freq.end());
        
        priority_queue<pair<int, int>>pq;
        
        for(int i = 25; i >= 0;) {
            if(freq[i] == 0) break;
            int cnt = 0, x = freq[i];
            while(i >= 0 && freq[i] == x) {
                i--, cnt++;
            }
            pq.push({x, cnt});
        }
        int ans = 1;
        while(!pq.empty() && k > 0) {
            auto tp = pq.top();
            pq.pop();
            
            int val = tp.first, cnt = tp.second;
            
            if(cnt <= k) {
                ans = (ans * 1ll * binExpo(val, cnt, mod)) % mod;
                k -= cnt;
            } else {
                long long num = fact[cnt];
                long long dem = (fact[k] * 1ll * fact[cnt - k]) % mod;
                
                ans = ((ans * 1ll * modInverse(num, dem, mod)) % mod * binExpo(val, k, mod)) % mod;
                k = 0;
                break;
            }
        }
        
        if(k != 0) return 0;

        return ans;
    }
};