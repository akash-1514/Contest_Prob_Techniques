class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> startTime, endTime;
        for(auto &i : intervals) {
            startTime.push_back(i[0]);
            endTime.push_back(i[1]);
        }
        
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());
        
        int i = 0, j = 0, ans = 0, cnt = 0;
        
        while(i < startTime.size()) {
            if(startTime[i] <= endTime[j]) {
                ans = max(ans, ++cnt);
                i++;
            } else {
                j++, cnt--;
            }
        }
        
        return ans;
    }
};