class Solution {
public:
    bool winnerOfGame(string colors) {
        int cntA = 0, cntB = 0, n = colors.size();
        for(int i = 1; i < n - 1; ++i) {
            if(colors[i] == 'A' && colors[i - 1] == 'A' && colors[i + 1] == 'A') cntA++;
            else if(colors[i] == 'B' && colors[i - 1] == 'B' && colors[i + 1] == 'B') cntB++;
        }
        return cntA > cntB;
    }
};