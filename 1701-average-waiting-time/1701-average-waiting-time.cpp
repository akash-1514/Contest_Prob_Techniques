class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long n = customers.size(), sum = 0, cTime = 1;
        for(auto &c : customers) {
            int startTime = c[0], prep = c[1];
            if(startTime > cTime) cTime = startTime;
            
            cTime += prep;
            
            sum += (cTime - startTime);
        }
        
        return (1.0 * sum / n);
    }
};