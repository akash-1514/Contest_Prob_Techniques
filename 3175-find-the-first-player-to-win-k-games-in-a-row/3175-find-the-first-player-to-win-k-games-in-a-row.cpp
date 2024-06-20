class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        int prev = skills[0], ans = 0, cnt = 0;
        for(int i = 1; i < n; ++i) {
            if(prev < skills[i]) {
                prev = skills[i];
                ans = i;
                cnt = 0;
            }
            cnt++;
            if(cnt >= k) return ans;
        }
        return ans;
    }
};