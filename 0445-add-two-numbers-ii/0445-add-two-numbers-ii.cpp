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
    ListNode* reverse(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* curr = head, *prev = NULL, *next = NULL;
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        ListNode* dummy = new ListNode(-1), *dptr = dummy;
        
        int c = 0;
        ListNode* ptr1 = l1, *ptr2 = l2;
        while(ptr1 != NULL || ptr2 != NULL) {
            int sum = 0;
            if(ptr1 != NULL) {
                sum += ptr1->val;
                ptr1 = ptr1->next;
            }
            if(ptr2 != NULL) {
                sum += ptr2->val;
                ptr2 = ptr2->next;
            }
            sum += c;
            int val = sum % 10;
            c = sum / 10;
            ListNode* newNode = new ListNode(val);
            dptr->next = newNode;
            dptr = dptr->next;
        }
        
        if(c != 0) {
            ListNode* newNode = new ListNode(c);
            dptr->next = newNode;
        }
        
        return reverse(dummy->next);
    }
};