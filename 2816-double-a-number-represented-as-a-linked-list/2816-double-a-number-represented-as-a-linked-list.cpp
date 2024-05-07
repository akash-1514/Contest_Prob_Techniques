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
        if(head == NULL || head->next == NULL) return head;
        ListNode* curr = head, *prev = NULL, *next = NULL;
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        ListNode* curr = head, *dummy = new ListNode(0), *dptr = dummy;
        int carry = 0;
        while(curr != NULL) {
            int res = curr->val * 2 + carry;
            int data = res % 10;
            carry = res / 10;
            ListNode* newNode = new ListNode(data);
            dptr->next = newNode;
            dptr = dptr->next;
            curr = curr->next;
        }
        
        if(carry) {
            ListNode* newNode = new ListNode(carry);
            dptr->next = newNode;
        }
        
        return reverse(dummy->next);
    }
};