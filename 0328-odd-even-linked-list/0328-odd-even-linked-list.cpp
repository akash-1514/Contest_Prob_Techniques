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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *curr1 = head, *curr2 = head->next;
        
        ListNode* odd = new ListNode(0), *oddPtr = odd;
        ListNode* even = new ListNode(0), *evenPtr = even;
        
        while(curr2 != NULL && curr2->next != NULL) {
            oddPtr->next = curr1;
            evenPtr->next = curr2;
            oddPtr = oddPtr->next;
            evenPtr = evenPtr->next;
            curr1 = curr1->next->next;
            curr2 = curr2->next->next;
        }
        
        if(curr2 == NULL) {
            oddPtr->next = curr1;
            oddPtr = oddPtr->next;
        } else {
            oddPtr->next = curr1;
            evenPtr->next = curr2;
            oddPtr = curr1, evenPtr = curr2;
        }
    
        oddPtr->next = even->next;
        evenPtr->next = NULL;
        return odd->next;
    }
};