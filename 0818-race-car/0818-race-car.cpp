class Solution {
public:
    int racecar(int target) {
        queue<pair<int, pair<int, int>>>q;
        unordered_map<int, unordered_map<int, int>>vis;
        vis[0][1] = 1;
        q.push({0, {0, 1}});
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            
            int steps = front.first, pos = front.second.first, speed = front.second.second;
            if(pos == target) return steps;
            
            // accelerate
            int newSpeed = 2 * speed;
            int newPos = pos + speed;
            if(!vis[newPos][newSpeed] && abs(pos - newPos) <= target) {
                vis[newPos][newSpeed] = 1;
                q.push({steps + 1, {newPos, newSpeed}});
            }
            
            // reverse
            if(speed > 0) {
                newSpeed = -1;
            } else {
                newSpeed = 1;
            }
            
            if(!vis[pos][newSpeed]) {
                vis[pos][newSpeed] = 1;
                q.push({steps + 1, {pos, newSpeed}});
            }
        }
        
        return -1;
    }
};