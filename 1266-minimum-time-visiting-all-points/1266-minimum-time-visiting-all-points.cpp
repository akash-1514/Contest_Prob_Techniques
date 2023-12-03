class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        int currX = points[0][0], currY = points[0][1];
        for(int i = 1; i < points.size(); ++i) {
            int xDiff = abs(currX - points[i][0]), yDiff = abs(currY - points[i][1]);
            time += (min(xDiff, yDiff) + abs(xDiff - yDiff));
            currX = points[i][0], currY = points[i][1];
        }
        return time;
    }
};