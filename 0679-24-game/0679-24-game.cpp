class Solution {
public:
    vector<double> getValidOperations(double a, double b) {
        vector<double> validOperations;
        validOperations.push_back(a + b);
        validOperations.push_back(a - b);
        validOperations.push_back(a * b);
        validOperations.push_back(b - a);
        if(abs(b) > FLT_EPSILON) {
            validOperations.push_back(a / b);
        } 
        if(abs(a) > FLT_EPSILON) {
            validOperations.push_back(b / a);
        }
        return validOperations;
    }
    bool helper(vector<double>&arr) {
        int n = arr.size();
        if(n == 1) {
            return abs(24 - arr[0]) <= FLT_EPSILON;
        }
        
        for(int fn = 0; fn < n; ++fn) {
            for(int sn = 0; sn < n; ++sn) {
                if(fn == sn) continue;
                double firstNum = arr[fn];
                double secondNum = arr[sn];
                vector<double> validOperations = getValidOperations(firstNum, secondNum);
                vector<double> newArr;
                for(auto &validOperation : validOperations) {
                    newArr.clear();
                    newArr.push_back(validOperation);
                    for(int i = 0; i < n; ++i) {
                        if(i != fn && i != sn) {
                            newArr.push_back(arr[i]);
                        }
                    }
                    if(helper(newArr)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double>arr(cards.begin(), cards.end());
        return helper(arr);
    }
};