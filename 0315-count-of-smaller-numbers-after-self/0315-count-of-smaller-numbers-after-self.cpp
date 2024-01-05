// necessary for using ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ------------------------------------------------------------------------------


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        oset<int>st;
        vector<int>ans(n, 0);
        for(int i = n - 1; i >= 0; --i) {
            int cntSmallerElements = st.order_of_key(nums[i]);
            ans[i] = cntSmallerElements;
            st.insert(nums[i]);
        }
        return ans;
    }
};