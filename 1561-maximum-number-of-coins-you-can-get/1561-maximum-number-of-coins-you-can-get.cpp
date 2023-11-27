class Solution {
public:
    static bool cmp(int a, int b) {
        return a > b;
    }
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), cmp);
        int j = 1, k = piles.size() - 1;
        int ans = 0;
        while(j < k) {
            ans += piles[j];
            j += 2, k--;
        }
        return ans;
    }
};