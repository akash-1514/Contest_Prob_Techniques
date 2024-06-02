class Solution {
public:
    int minimumChairs(string s) {
        int cnt = 0, mx = 0;
        for(char ch : s) {
            if(ch == 'E') cnt++;
            else cnt--;
            
            mx = max(mx, cnt);
        }
        return mx;
    }
};