/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head) {
        ListNode* curr = head;
        int len = 0;
        while(curr != NULL) {
            len++;
            curr = curr->next;
        }
        return len;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if(k == 1) {
            return {head};
        }
        vector<ListNode*>ans(k);
        int len = length(head), sz = len / k, extra = len % k, idx = 0;
        ListNode* curr = head;
        while(curr != NULL) {
            int cnt = 1;
            ListNode* currHead = curr, *prev = curr;
            while(curr != NULL && cnt <= sz) {
                prev = curr;
                curr = curr->next;
                cnt++;
            }
            if(extra > 0) {
                prev = curr;
                curr = curr->next;
                extra--;
            }
            prev->next = NULL;
            ans[idx++] = currHead;
        }
        
        return ans;
    }
};