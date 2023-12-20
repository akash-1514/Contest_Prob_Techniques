class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mn = 1e9, mn2 = 1e9;
        for(int ele : prices) {
            if(ele < mn) {
                mn2 = mn;
                mn = ele;
            } else if(ele < mn2) {
                mn2 = ele;
            }
        }
        return (money - (mn + mn2) < 0 ? money : money - (mn + mn2));
    }
};