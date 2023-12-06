class Solution {
public:
    int totalMoney(int n) {
        int money = 0, prev = 1, cnt = 1;
        for(int i = 1; i <= n; ++i) {
            if((i - 1) % 7 == 0) {
                money += cnt;
                prev = cnt++;
            } else {
                money += (++prev);
            }
        }
        
        return money;
    }
};