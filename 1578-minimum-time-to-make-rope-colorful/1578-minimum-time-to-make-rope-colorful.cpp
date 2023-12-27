class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, n = colors.size();
        for(int i = 0; i < n;) {
            int mx = neededTime[i];
            char curr = colors[i];
            int sum = 0;
            while(i < n && colors[i] == curr) {
                sum += neededTime[i];
                mx = max(mx, neededTime[i]);
                i++;
            }
            ans += (sum - mx);
        }
        return ans;
    }
};