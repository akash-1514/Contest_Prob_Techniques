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
    vector<TreeNode*> helper(int low, int high) {
        if(low > high) {
            return {NULL};
        }
        
        vector<TreeNode*> vec;
        for(int k = low; k <= high; ++k) {
            vector<TreeNode*> left = helper(low, k - 1);
            vector<TreeNode*> right = helper(k + 1, high);
            
            for(int i = 0; i < left.size(); ++i) {
                for(int j = 0; j < right.size(); ++j) {
                    TreeNode* root = new TreeNode(k);
                    root->left = left[i];
                    root->right = right[j];
                    vec.push_back(root);
                }
            }
        }
        return vec;
    }
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
};