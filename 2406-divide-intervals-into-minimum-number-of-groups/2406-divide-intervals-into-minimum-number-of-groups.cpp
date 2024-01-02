class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int>mp;
        for(auto &i : intervals) mp[i[0]]++, mp[i[1] + 1]--;
        int mx = 0, cnt = 0;
        for(auto &it : mp) {
            cnt += it.second;
            mx = max(mx, cnt);
        }
        return mx;
    }
};