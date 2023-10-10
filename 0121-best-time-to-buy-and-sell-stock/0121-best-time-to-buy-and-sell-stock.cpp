class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mx = prices[n - 1], profit = 0;
        for(int i = n - 2; i >= 0; --i) {
            profit = max(profit, mx - prices[i]);
            mx = max(mx, prices[i]);
        }
        return profit;
    }
};