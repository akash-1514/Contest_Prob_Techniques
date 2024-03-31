class Solution {
public:
    int maxBottlesDrunk(int numBottle, int numExchange) {
        int ans = numBottle;
        while(numBottle != 0) {
            if(numBottle >= numExchange) {
                ans++;
                numBottle += 1;
                numBottle -= numExchange;
                numExchange++;
            } else {
                break;
            }
        }
        return ans;
    }
};