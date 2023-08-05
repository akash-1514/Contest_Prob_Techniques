/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> helper(vector<int>&arr, int low, int high) {
        if(low > high) return {NULL};
        
        vector<TreeNode*> res;
        for(int i = low; i <= high; ++i) {
            vector<TreeNode*> left = helper(arr, low, i - 1);
            vector<TreeNode*> right = helper(arr, i + 1, high);
            for(int j = 0; j < left.size(); ++j) {
                for(int k = 0; k < right.size(); ++k) {
                    TreeNode* root = new TreeNode(arr[i]);
                    root->left = left[j];
                    root->right = right[k];
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<int> vec;
        for(int i = 1; i <= n; ++i) vec.push_back(i);
        return helper(vec, 0, n - 1);
    }
};