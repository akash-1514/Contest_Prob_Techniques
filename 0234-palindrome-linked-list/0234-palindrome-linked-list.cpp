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
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head, *prev = NULL, *next = NULL;
        
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* newHead = slow->next;
        slow->next = NULL;
        
        newHead = reverse(newHead);
        
        ListNode* t1 = head, *t2 = newHead;
        
        while(t1 != NULL && t2 != NULL)
        {
            if(t1->val != t2->val) return false;
            t1 = t1->next, t2 = t2->next;
        }
        
        return true;
    }
};