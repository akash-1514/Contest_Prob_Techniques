class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>>pq;
        long long sum = 0, tot = 0, ans = 0;
        for(int i = 1; i < n; ++i) {
            if(heights[i] > heights[i - 1]) {
                int diff = heights[i] - heights[i - 1];
                tot += diff;
                if(ladders > 0) {
                    if(pq.size() < ladders) {
                        sum += diff;
                        pq.push(diff);
                    } else if(pq.size() == ladders) {
                        if(diff > pq.top()) {
                            sum -= pq.top();
                            pq.pop();
                            sum += diff;
                            pq.push(diff);
                        }
                    }
                } 
            }
            if(tot - sum <= bricks) {
                ans = i;
            }
        }
        return ans;
    }
};