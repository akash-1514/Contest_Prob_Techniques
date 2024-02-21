class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int>pq;
        int sum = 0;
        for(int i = 1; i < n; ++i) {
            int diff = heights[i] - heights[i - 1];
            if(diff > 0) {
                sum += diff;
                pq.push(diff);
                if(sum > bricks) {
                    if(ladders) {
                        sum -= pq.top();
                        pq.pop();
                        ladders--;
                    } 
                }
                if(sum > bricks) {
                    return i - 1;
                }
            } 
        }
        return n - 1;
    }
};