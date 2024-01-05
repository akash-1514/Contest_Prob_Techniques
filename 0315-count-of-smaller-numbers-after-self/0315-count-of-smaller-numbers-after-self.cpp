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

     void Update(int node, int L, int R, int pos)
     {
          if (L == R)
          {
               st[node]++;
               return;
          }
          int M = (L + R) / 2;
          if (pos <= M)
               Update(node * 2 + 1, L, M, pos);
          else
               Update(node * 2 + 2, M + 1, R, pos);

          st[node] = st[node * 2 + 1] + st[node * 2 + 2];
     }

     int Query(int node, int L, int R, int i, int j)
     {
          if (j < L || i > R)
               return 0;
          if (i <= L && R <= j)
               return st[node];
          int M = (L + R) / 2; 
          return Query(node * 2 + 1, L, M, i, j) + Query(node * 2 + 2, M + 1, R, i, j);
          
     }

    
     int query(int l, int r) { return Query(0, 0, N - 1, l, r); }

     void update(int pos) { Update(0, 0, N - 1, pos); }

     void build(vector<int>&b) { Build(0, 0, N - 1, b); }

};
class Solution {
public:
    // Aproach1: Ordered set(Policy DS) 
    // Approach2: Segment Tree
    // Approach3: Merge Sort
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        SegTree seg;
        seg.init(20001);
        vector<int>ans(n);
        for(int i = n - 1; i >= 0; --i) {
            int count = seg.query(0, nums[i] + 9999);
            ans[i] = count;
            seg.update(nums[i] + 10000);
        }
        return ans;
    }
};