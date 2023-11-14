class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size();
        sort(products.begin(), products.end());
        string prefix = "";
        vector<vector<string>>ans;
        int bStart = 0;
        for(char ch : searchWord) {
            prefix += ch;
            
            auto idx = lower_bound(products.begin() + bStart, products.end(), prefix) - products.begin();
            
            vector<string>res;
            for(int i = idx; i < min((int)idx + 3, n) && !products[i].compare(0, prefix.size(), prefix); ++i) {
                res.push_back(products[i]);
            }
            ans.push_back(res);
        }
        return ans;
    }
};