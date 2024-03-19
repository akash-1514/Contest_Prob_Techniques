class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char ch : tasks) {
            freq[ch - 'A']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        priority_queue<int>pq;
        for(int i = 0; i < 26; ++i) {
            if(freq[i] > 0) pq.push(freq[i]);
        }
        
        int time = 0;
        while(!pq.empty()) {
            vector<int> temp;
            for(int i = 1; i <= (n + 1) && !pq.empty(); ++i) {
                int tp = pq.top(); pq.pop();
                temp.push_back(tp - 1);
            }
            
            for(int ele : temp) {
                if(ele > 0) pq.push(ele);
            }
            
            if(pq.empty()) {
                time += temp.size();
            } else {
                time += (n + 1);
            }
        }
        return time;
    }
};