class Solution {
public:
    int bestClosingTime(string customers) {
        int idx = -1, cnt = 0, mx = 0;
        for(int i = 0; i < customers.size(); ++i) {
            if(customers[i] == 'Y') {
                cnt++;
            } else {
                cnt--;
            }
            if(cnt > mx) {
                mx = cnt;
                idx = i;
            }
        }
        return idx + 1;
    }
};