class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(), sz = n / 4;
        for(int i = 0; i < n - sz; ++i) {
            if(arr[i] == arr[i + sz]) {
                return arr[i];
            }
        }
        return -1;
    }
};