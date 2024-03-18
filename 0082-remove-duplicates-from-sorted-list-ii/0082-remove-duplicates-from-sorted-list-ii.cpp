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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy, *curr = head;
        while(curr != NULL) {
            if(curr->next != NULL) {
                if(curr->val == curr->next->val) {
                    while(curr->next != NULL && curr->val == curr->next->val) {
                        curr = curr->next;
                    }
                } else {
                    prev->next = curr;
                    prev = curr;
                }
            } else {
                prev->next = curr;
                prev = curr;
            }
            curr = curr->next;
        }
        prev->next = NULL;
        return dummy->next;
    }
};