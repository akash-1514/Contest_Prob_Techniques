class Solution {
public:
    int mod = 1e9 + 7;
    int numberOfWays(string corridor) {
        int ways = 1, n = corridor.size(), seats = 0, partition = 0;
        bool found = false;
        for(int i = 0; i < n; ++i) {
            if(corridor[i] == 'S') {
                if(seats == 2) {
                    ways = (ways * 1ll * (partition + 1)) % mod;
                    seats = 0, partition = 0;
                }
                seats++;
                if(seats == 2) found = true;
            } else {
                if(seats == 2) {
                    if(corridor[i] == 'P') {
                        partition++;
                    }
                }
            }
        }
        if((seats == 2 || seats == 0) && found) {
            return ways;
        } else {
            return 0;
        }
    }
};