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
private:
    unordered_map<int, int> mp;
public:
    TreeNode* dfs(TreeNode* root, vector<TreeNode*>&ans) {
        if(!root) return NULL;
        
        root->left = dfs(root->left, ans);
        root->right = dfs(root->right, ans);
        
        if(mp.find(root->val) != mp.end()) {
            if(root->left != NULL) ans.push_back(root->left);
            if(root->right != NULL) ans.push_back(root->right);
            return NULL;
        } else {
            return root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        for(int ele : to_delete) mp[ele]++;
        TreeNode* res = dfs(root, ans);
        if(res != NULL) ans.push_back(res);
        return ans;
    }
};