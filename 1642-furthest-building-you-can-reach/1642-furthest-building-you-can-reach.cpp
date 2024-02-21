class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int>pq;
        int ans = 0;
        for(int i = 1; i < n; ++i) {
            int diff = heights[i] - heights[i - 1];
            if(diff > 0) {
                pq.push(-diff);
                if(pq.size() > ladders) {
                    if(!pq.empty()) {
                        bricks += pq.top();
                        pq.pop();
                    }
                }
            }
            if(bricks >= 0) {
                ans = i;
            }
        }
        return ans;
    }
};