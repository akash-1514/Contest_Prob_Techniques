class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int i = 0, j = n - 1;
        int mx = 0, score = 0;
        while(i <= j) {
            if(power >= tokens[i]) {
                mx = max(mx, ++score);
                power -= tokens[i];
                i++;
            } else {
                if(score >= 1) {
                    power += tokens[j];
                    score--, j--;
                } else {
                    break;
                }
            }
        }
        return mx;
    }
};