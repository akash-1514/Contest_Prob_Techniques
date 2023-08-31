class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        
        int ans = 0, currLen = 0, maxLen = -1e9, idx = 0;
        
        while(idx < clips.size()) {
            if(clips[idx][0] <= currLen) {
                maxLen = max(maxLen, clips[idx][1]);
                idx++;
            } else {
                if(maxLen == -1e9 || maxLen <= currLen) return -1;
                else {
                    currLen = maxLen;
                    maxLen = -1e9;
                    ans++;
                    if(currLen >= time) {
                        return ans;
                    }
                }
            }
        }
        
        return maxLen >= time ? ans + 1 : -1;
    }
};