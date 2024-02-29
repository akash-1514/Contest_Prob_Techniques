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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;
        while(!q.empty()) {
            int size = q.size();
            int prev = -1;
            while(size--) {
                auto front = q.front();
                q.pop();
                
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);

                if(lvl & 1) {
                    if(front->val & 1) return false;
                    if(prev == -1) {
                        prev = front->val;
                    } else {
                        if(front->val >= prev) return false;
                        prev = front->val;
                    }
                } else {
                    if(front->val % 2 == 0) return false;
                    if(prev == -1) {
                        prev = front->val;
                    } else {
                        if(front->val <= prev) return false;
                        prev = front->val;
                    }
                }
            }
            lvl++;
        }
        return true;
    }
};