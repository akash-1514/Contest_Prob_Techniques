#define ppi pair<int, pair<int, int>>
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<ppi, vector<ppi>, greater<ppi>>pq;
        for(int i = 0; i < nums2.size(); ++i) {
            pq.push({nums1[0] + nums2[i], {0, i}});
        }
        
        vector<vector<int>>ans;
        
        while(!pq.empty() && k--) {
            auto tp = pq.top();
            pq.pop();
            int sum = tp.first, idx1 = tp.second.first, idx2 = tp.second.second;
            ans.push_back({nums1[idx1], nums2[idx2]});
            if(idx1 + 1 < nums1.size()) {
                pq.push({nums1[idx1 + 1] + nums2[idx2], {idx1 + 1, idx2}});
            }
        }
        return ans;
    }
};