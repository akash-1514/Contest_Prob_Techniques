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
    void reverse(ListNode*&head, ListNode* start, ListNode* end) {
        ListNode* curr = start, *prev = NULL, *next = NULL;
        while(prev != end) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL || left == right) return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* beforeStart = dummy, *end = head;
        int cnt = 1;
        while(end != NULL && cnt != right) {
            if(cnt == left - 1) {
                beforeStart = end;
            }
            cnt++;
            end = end->next;
        }
        
        ListNode* start = beforeStart->next, *nextEnd = end->next;
        
        reverse(head, start, end);
        
        beforeStart->next = end;
        start->next = nextEnd;
        
        return dummy->next;
    }
};