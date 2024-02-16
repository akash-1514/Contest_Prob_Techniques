class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int>mp;
        for(int i = 0; i < n; ++i) {
            mp[arr[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(auto &it : mp) {
            pq.push({it.second, it.first});
        }
        while(!pq.empty() && k != 0) {
            int freq = pq.top().first, ele = pq.top().second;
            pq.pop();
            if(freq <= k) {
                k -= freq;
            } else {
                pq.push({freq - k, ele});
                break;
            }
        }
        
        return pq.size();
    }
};