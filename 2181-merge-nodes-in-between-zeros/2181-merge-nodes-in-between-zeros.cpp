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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0), *dptr = dummy, *temp = head->next;
        int sum = 0;
        while(temp != NULL) {
            if(temp->val == 0) {
                ListNode* newNode = new ListNode(sum);
                dptr->next = newNode;
                dptr = dptr->next;
                sum = 0;
            } else {
                sum += temp->val;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};