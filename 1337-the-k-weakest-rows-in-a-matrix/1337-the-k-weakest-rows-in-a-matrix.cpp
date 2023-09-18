class Solution {
public:
    int countAllOnes(vector<int>&arr) {
        int low = 0, high = arr.size() - 1, ans = -1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(arr[mid] == 1) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans + 1;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<pair<int, int>>vec;
        for(int i = 0; i < n; ++i) {
            int cnt = countAllOnes(mat[i]);
            vec.push_back({cnt, i});
        }
        
        sort(vec.begin(), vec.end());
        
        vector<int>ans;
        for(int i = 0; i < k; ++i) {
            ans.push_back(vec[i].second);
        }
        return ans;
    }
};