static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
struct SegTree
{
     int N;
     vector<int> st;
    
     void init(int n)
     {
          N = n;
          st.resize(4 * N + 5, 0);
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
          st[node] = st[node * 2 + 1] + st[node * 2 + 2];
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
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        SegTree seg;
        seg.init(100001);
        int ans = 1;
        for(int i = 0; i < n; ++i) {
            int l = max(0, nums[i] - k), r = nums[i] - 1;
            int maxLen = seg.query(l, r);
            ans = max(ans, maxLen + 1);
            seg.update(nums[i], maxLen + 1);
        }
        return ans;
    }
};