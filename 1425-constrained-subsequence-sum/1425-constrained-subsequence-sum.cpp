struct SegTree
{
     int N;
     vector<int> st;
    
     void init(int n)
     {
          N = n;
          st.resize(4 * N + 5);
     }

     

     void Build(int node, int L, int R, vector<int>&b)
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

     void Update(int node, int L, int R, int pos, int val)
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

     int Query(int node, int L, int R, int i, int j)
     {
          if (j < L || i > R)
               return 0;
          if (i <= L && R <= j)
               return st[node];
          int M = (L + R) / 2; 
          return max(Query(node * 2 + 1, L, M, i, j), Query(node * 2 + 2, M + 1, R, i, j));
          
     }

     

     int query(int l, int r) { return Query(0, 0, N - 1, l, r); }

     void update(int pos, int val) { Update(0, 0, N - 1, pos, val); }

     void build(vector<int>&b) { Build(0, 0, N - 1, b); }

};

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        SegTree seg;
        seg.init(n);
        vector<int> dp(n, 0);
        dp[n - 1] = nums[n - 1];
        seg.update(n - 1, dp[n - 1]);
        int mx = dp[n - 1];
        for(int i = n - 2; i >= 0; --i) {
            dp[i] = nums[i] + seg.query(i + 1, min(i + k, n - 1));
            seg.update(i, dp[i]);
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};