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
        int len = 0;
        ListNode* curr = head;
        while(curr != NULL) {
            curr = curr->next;
            len++;
        }
        return len;
    }
    ListNode* helper(ListNode* head, int k, int len) {
        if(len == 0 || head->next == NULL || head == NULL) {
            return head;
        }
        
        int cnt = 1;
        ListNode* curr = head, *prev = NULL, *next;
        while(curr != NULL && cnt <= k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        
        head->next = helper(curr, k, len - 1);
        
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = length(head);
        return helper(head, k, len / k);
    }
};