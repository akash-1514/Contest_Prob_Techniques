class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int s = 0;
        int temp = x;
        while(temp != 0) {
            s += (temp % 10);
            temp /= 10;
        }
        
        if(x % s == 0) return s;
        return -1;
    }
};