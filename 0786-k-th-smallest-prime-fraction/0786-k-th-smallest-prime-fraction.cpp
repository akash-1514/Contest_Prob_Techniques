class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>>pq;
        for(int i = 0; i < arr.size(); ++i) {
            for(int j = i + 1; j < arr.size(); ++j) {
                double x = (1.0 * arr[i] / arr[j]);
                pq.push({x, {i, j}});
                if(pq.size() > k) pq.pop();
            }
        }
        int idx1 = pq.top().second.first, idx2 = pq.top().second.second;
        return {arr[idx1], arr[idx2]};
    }
};