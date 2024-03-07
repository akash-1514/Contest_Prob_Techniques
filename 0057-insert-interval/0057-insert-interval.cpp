class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>>ans;
        
        bool fl = false, fl2 = false;
        for(int i = 0; i < n; ++i) {
            if(max(intervals[i][0], newInterval[0]) <= min(intervals[i][1], newInterval[1])) {
                    newInterval = {min(intervals[i][0], newInterval[0]), max(intervals[i][1], newInterval[1])};
                fl = true;
                fl2 = true;
            } else {
                if(fl) {
                    ans.push_back(newInterval);
                    ans.push_back(intervals[i]);
                    fl = false;
                } else {
                    if(!fl2 && newInterval[1] < intervals[i][0]) {
                        fl2 = true;
                        ans.push_back(newInterval);
                    }
                    ans.push_back(intervals[i]);    
                }
            }
        }
        if(fl) {
            ans.push_back(newInterval);
        }
        
        if(!fl2) {
            ans.push_back(newInterval);
        }
        return ans;
    }
};