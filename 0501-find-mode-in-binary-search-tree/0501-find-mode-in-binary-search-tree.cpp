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
    unordered_map<int, int>mp;
    int mxFreq = 0;
    void dfs(TreeNode* root) {
        if(!root) return;
        mp[root->val]++;
        mxFreq = max(mxFreq, mp[root->val]);
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        if(root == NULL) {
            return {};
        }
        dfs(root);
        vector<int>ans;
        for(auto &it : mp) {
            if(it.second == mxFreq) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};