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
    void dfs(TreeNode* root, string &res, string &ans) {
        if(!root) return;
        res += (root->val + 'a');
        if(!root->left && !root->right) {
            reverse(res.begin(), res.end());
            if(ans == "") ans = res;
            else ans = min(ans, res);
            reverse(res.begin(), res.end());
            res.pop_back();
            return;
        }
        
        dfs(root->left, res, ans);
        dfs(root->right, res, ans);
        
        res.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "", res = "";
        dfs(root, res, ans);
        return ans;
    }
};