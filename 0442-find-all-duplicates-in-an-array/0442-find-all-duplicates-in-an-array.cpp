class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        int i = 0, n = arr.size();
        while(i < n) {
            int correctIdx = arr[i] - 1;
            if(arr[correctIdx] != arr[i]) {
                swap(arr[correctIdx], arr[i]);
            } else {
                i++;
            }
        }
        
        vector<int>ans;
        for(int i = 0; i < n; ++i) {
            if(arr[i] != (i + 1)) {
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};