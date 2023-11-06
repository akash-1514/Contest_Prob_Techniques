#define ll long long
struct SegTree
{
     int N;
     vector<ll> st;
    
     void init(int n)
     {
          N = n;
          st.resize(4 * N + 5, 0);
     }

     void Build(ll node, int L, int R, vector<ll>&b)
     {
          if (L == R)
          {
               st[node] = b[L];
               return;
          }
          int M = (L + R) / 2;
          Build(node * 2 + 1, L, M, b);
          Build(node * 2 + 2, M + 1, R, b);
          st[node] = max(st[node * 2 + 1], st[node * 2 + 2]);
     }

     void Update(ll node, int L, int R, int pos, ll val)
     {
          if (L == R)
          {
               st[node] = val;
               return;
          }
          int M = (L + R) / 2;
          if (pos <= M)
               Update(node * 2 + 1, L, M, pos, val);
          else
               Update(node * 2 + 2, M + 1, R, pos, val);

          st[node] = max(st[node * 2 + 1], st[node * 2 + 2]);
     }

     long long Query(ll node, int L, int R, int i, int j)
     {
          if (j < L || i > R)
               return 0;
          if (i <= L && R <= j)
               return st[node];
          int M = (L + R) / 2; 
          return max(Query(node * 2 + 1, L, M, i, j), Query(node * 2 + 2, M + 1, R, i, j));
          
     }

     long long query(int l, int r) { return Query(0, 0, N - 1, l, r); }

     void update(int pos, ll val) { Update(0, 0, N - 1, pos, val); }

     void build(vector<long long>&b) { Build(0, 0, N - 1, b); }

};
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
    
        SegTree seg;
        seg.init(n);
        
        vector<ll> dp(n, 0);
        vector<pair<ll, ll>> arr;
        for(int i = 0; i < n; ++i) {
            arr.push_back({nums[i] - i, i});
        }
        
        sort(arr.begin(), arr.end());
        
        long long ans = LONG_MIN;
        for(auto &it : arr) {
            int idx = it.second;
            long long mx = seg.query(0, idx - 1);
            dp[idx] = nums[idx] + mx; 
            seg.update(idx, dp[idx]);
            ans = max(ans, dp[idx]); 
        }
        return ans;
    }
};