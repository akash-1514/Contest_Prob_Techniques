class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int>mp;
        for(auto &m : matches) mp[m[1]]++;
        vector<int> loser, winner;
        for(int i = 0; i < matches.size(); ++i) {
            int w = matches[i][0], l = matches[i][1];
            if(mp.find(l) != mp.end() && mp[l] == 1) {
                loser.push_back(l);
                mp[l] = 2;
            }
            
            if(mp.find(w) == mp.end()) {
                winner.push_back(w);
                mp[w] = 2;
            }
        }
        sort(loser.begin(), loser.end());
        sort(winner.begin(), winner.end());
        return {winner, loser};
    }
};