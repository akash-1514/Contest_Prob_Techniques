class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0, cost = 0, mx = 0;
        for(int j = 0; j < s.size(); ++j) {
            cost += abs(s[j] - t[j]);
            while(cost > maxCost) {
                cost -= abs(s[i] - t[i]);
                i++;
            }
            mx = max(mx, j - i + 1);
        }
        return mx;
    }
};