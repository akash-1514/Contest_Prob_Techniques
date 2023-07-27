class Solution {
public:
    bool pred(vector<int>&dist, int mid, double hour) {
        double time = 0.0;
        for(int i = 0; i < dist.size(); ++i) {
            if(i == dist.size() - 1) {
                time += (1.0 * dist[i] / mid);
            } else {
                time += ceil((1.0 * dist[i]) / mid);
            }
        }
        return time <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1, high = 1e7, ans = -1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            cout << mid << endl;
            if(pred(dist, mid, hour)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};