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
    map<TreeNode*, TreeNode*>parentChild;
    TreeNode* startNode = NULL;
public:
    void bfs(TreeNode* root, int x) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            
            if(front->val == x) {
                startNode = front;
            }
            
            if(front->left != NULL) {
                parentChild[front->left] = front;
                q.push(front->left);
            }
            
            if(front->right != NULL) {
                parentChild[front->right] = front;
                q.push(front->right);
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        bfs(root, start);
        queue<pair<int, TreeNode*>>q;
        q.push({0, startNode});
        unordered_map<TreeNode*, bool>vis;
        vis[startNode] = true;
        int ans = 0;
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            
            TreeNode* node = front.second;
            cout << node->val << endl;
            int time = front.first;
            ans = max(ans, time);
            
            if(node->left != NULL && !vis[node->left]) {
                vis[node->left] = true;
                q.push({time + 1, node->left});
            }
            
            if(node->right != NULL && !vis[node->right]) {
                vis[node->right] = true;
                q.push({time + 1, node->right});
            }
            
            if(parentChild[node] != NULL && !vis[parentChild[node]]) {
                vis[parentChild[node]] = true;
                q.push({time + 1, parentChild[node]});
            }
        }
        return ans;
    }
};