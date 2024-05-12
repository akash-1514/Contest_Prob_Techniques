class Solution {
public:
    bool check(vector<vector<int>>&points, int mid, string &s) {
        if(mid == 0) return true;
        vector<int> freq(26, 0);
        for(int i = 0; i < points.size(); ++i) {
            int x = abs(points[i][0]), y = abs(points[i][1]);
            if(x <= mid && y <= mid) {
                freq[s[i] - 'a']++;
            }
        }
        
        for(int ele : freq) {
            if(ele > 1) {
                return false;
            }
        }
        
        return true;
    }
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        long long low = 0, high = 1e9, res = 0;
        while(low <= high) {
            long long mid = (low + high) >> 1;
            if(check(points, mid, s)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        int ans = 0;
        for(auto p : points) {
            int x = abs(p[0]), y = abs(p[1]);
            if(x <= res && y <= res) {
                ans++;
            }
        }
        
        return ans;
    }
};