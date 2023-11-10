class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int mx = *max_element(arr.begin(), arr.end()), n = arr.size();
        if(k >= arr.size() - 1) {
            return mx;
        }
        deque<int>q;
        for(int i = 0; i < n; ++i) {
            q.push_back(arr[i]);
        }
        int i = 1, prev = -1, cnt = 0;
        while(i <= n) {
            int ele1 = q.front(); q.pop_front();
            int ele2 = q.front(); q.pop_front();
            if(ele1 > ele2) {
                if(ele1 == prev) {
                    cnt++; 
                    if(cnt >= k) {
                        return ele1;
                    }
                } else {
                    cnt = 1;
                    if(cnt >= k) return ele1;
                    prev = ele1;
                }
                q.push_front(ele1);
                q.push_back(ele2);
            } else {
                if(ele2 == prev) {
                    cnt++;
                    if(cnt >= k) return ele2;
                } else {
                    cnt = 1;
                    if(cnt >= k) return ele2;
                    prev = ele2;
                }
                q.push_back(ele1);
                q.push_front(ele2);
            }
        }
        
        return mx;
    }
};