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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0), *dptr = dummy;
        ListNode* p1 = list1, *p2 = list2;
        while(p1 != NULL && p2 != NULL) {
            if(p1->val < p2->val) {
                dptr->next = p1;
                p1 = p1->next;
            } else {
                dptr->next = p2;
                p2 = p2->next;
            }
            dptr = dptr->next;
        }
        if(p1 != NULL) dptr->next = p1;
        if(p2 != NULL) dptr->next = p2;
        return dummy->next;
    }
};