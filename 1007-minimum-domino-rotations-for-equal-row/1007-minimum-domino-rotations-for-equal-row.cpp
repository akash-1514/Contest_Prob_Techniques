class Solution {
public:
    int minDominoRotations(vector<int>& top, vector<int>& bottom) {
        int n = top.size();
        int mn = 1e9;
        // only concern to change the top halve
        for(int i = 1; i <= 6; ++i) {
            int cnt = 0, cnt2 = 0;
            bool valid = true;
            for(int j = 0; j < n; ++j) {
                if(top[j] == i && bottom[j] == i) continue;
                if(top[j] != i && bottom[j] != i) {
                    valid = false;
                    break;
                } else {
                    if(top[j] != i) {
                        cnt++;
                    } else {
                        cnt2++;
                    }
                }
            }
            if(valid) {
                mn = min({mn, cnt, cnt2});
            }
        }
        
        return mn == 1e9 ? -1 : mn;
    }
};