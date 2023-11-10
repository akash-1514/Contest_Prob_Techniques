class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if((sx == fx && sy == fy) && t == 1) {
            return false;
        }
        
        int xDiff = abs(sx - fx);
        int yDiff = abs(sy - fy);
        int shortestTime = min(xDiff, yDiff) + abs(xDiff - yDiff); 
        return t >= shortestTime;
    }
};