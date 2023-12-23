class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>>vis = {{0, 0}};
        int x = 0, y = 0;
        for(char ch : path) {
            if(ch == 'N') {
                y++;
            } else if(ch == 'S') {
                y--;
            } else if(ch == 'W') {
                x--;
            } else {
                x++;
            }
            if(vis.find({x, y}) != vis.end()) return true;
            vis.insert({x, y});
        }
        return false;
    }
};