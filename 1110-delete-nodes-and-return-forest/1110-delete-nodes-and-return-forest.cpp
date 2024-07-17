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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        queue<TreeNode*>q;
        unordered_map<int, int>mp;
        for(int ele : to_delete) mp[ele]++;
        
        vector<TreeNode*>ans;
        
        q.push(root);
        
        while(!q.empty()) {
            auto front = q.front(); q.pop();
            // presenting the idea of postorder traversal into bfs
            // left right root
            
            // left
            if(front->left) {
                q.push(front->left);
                if(mp.find(front->left->val) != mp.end()) {
                    front->left = NULL;
                }
            }
            
            // right
            if(front->right) {
                q.push(front->right);
                if(mp.find(front->right->val) != mp.end()) {
                    front->right = NULL;
                }
            }
            
            if(mp.find(front->val) != mp.end()) {
                if(front->left) ans.push_back(front->left);
                if(front->right) ans.push_back(front->right);
            }
        }
        
        if(mp.find(root->val) == mp.end()) {
            ans.push_back(root);
        }

        
        return ans;
    }
};