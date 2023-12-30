class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int>pq;
        int ans = 0;
        for(int i = 1; i < n; ++i) {
            int diff = heights[i] - heights[i - 1];
            if(diff > 0) {
                if(pq.size() < ladders) {
                    pq.push(-diff);
                } else {
                    if(!pq.empty() && diff > -1 * pq.top()) {
                        bricks += pq.top();
                        pq.pop();
                        pq.push(-diff);
                    } else {
                        bricks -= diff;
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