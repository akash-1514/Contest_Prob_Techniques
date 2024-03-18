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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode* curr1 = l1, *curr2 = l2, *dummy = new ListNode(0), *dptr = dummy;
        while(curr1 != NULL && curr2 != NULL) {
            int sum = curr1->val + curr2->val + c;
            ListNode* newNode = new ListNode(sum % 10);
            dptr->next = newNode;
            dptr = dptr->next;
            curr1 = curr1->next, curr2 = curr2->next;
            c = sum / 10;
        }
        
        while(curr1 != NULL) {
            int sum = curr1->val + c;
            ListNode* newNode = new ListNode(sum % 10);
            dptr->next = newNode;
            dptr = dptr->next;
            curr1 = curr1->next;
            c = sum / 10;
        }
        
        while(curr2 != NULL) {
            int sum = curr2->val + c;
            ListNode* newNode = new ListNode(sum % 10);
            dptr->next = newNode;
            dptr = dptr->next;
            curr2 = curr2->next;
            c = sum / 10;
        }
        
        if(c != 0) {
            ListNode* node = new ListNode(c);
            dptr->next = node;
        }
        
        return dummy->next;
    }
};