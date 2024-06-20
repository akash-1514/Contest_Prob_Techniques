class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        deque<int>q;
        int mx = 0, idx = 0;
        for(int i = 0; i < n; ++i) {
            q.push_back(i);
            if(skills[i] > mx) {
                mx = skills[i];
                idx = i;
            }
        }
        
        int prev = 0, cnt = 0;
        for(int i = 0; i < n; ++i) {
            int idx1 = q.front(); q.pop_front();
            int idx2 = q.front(); q.pop_front();
            if(skills[idx1] > skills[idx2]) {
                q.push_front(idx1);
                q.push_back(idx2);
            } else {
                q.push_front(idx2);
                q.push_back(idx1);
            }
            
            if(q.front() == prev) {
                cnt++;
            } else {
                prev = q.front();
                cnt = 1;
            }
            if(cnt == k) return q.front();
        }
        return idx;
    }
};