class Solution {
public:
    vector<int> computeLPS(string &word) {
        int n = word.size();
        vector<int>lps(n, 0);
        lps[0] = 0;
        int i = 1, length = 0;
        while(i < n) {
            if(word[i] == word[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if(length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        vector<int> lps = computeLPS(word);
        int maxLPSLen = lps[n - 1];
        while((n - maxLPSLen) % k != 0 && maxLPSLen > 0) {
            maxLPSLen = lps[maxLPSLen - 1];
        }
        return (n - maxLPSLen) % k == 0 ? (n - maxLPSLen) / k : ceil(1.0 * n / k);
    }
};