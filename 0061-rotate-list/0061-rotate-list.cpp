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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* curr = head;
        int len = 1;
        while(curr->next != NULL) {
            curr = curr->next;
            len++;
        }
        
        k %= len;
        if(k == 0) return head;
        
        int idx = 1;
        ListNode* ptr = head;
        while(ptr != NULL && idx != len - k) {
            ptr = ptr->next;
            idx++;
        }
        
        curr->next = head;
        ListNode* ans = ptr->next;
        ptr->next = NULL;
        return ans;
    }
};