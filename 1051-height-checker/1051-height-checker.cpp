class Solution {
public:
    int heightChecker(vector<int>& heights) {
        priority_queue<int>pq;
        for(int ele : heights) pq.push(-1 * ele);
        int ans = 0;
        for(int ele : heights) {
            if(ele != (-1 * pq.top())) {
                ans++;
            }
            pq.pop();
        }
        return ans;
    }
};