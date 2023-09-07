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
    void reverse(ListNode* start, ListNode* end) {
        ListNode* curr = start, *prev = NULL, *next = NULL;
        while(prev != end) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0), *beforeStart = dummy, *end = head;
        dummy->next = head;
        
        int cnt = 1;
        while(end != NULL) {
            if(cnt % k == 0) {
                ListNode* start = beforeStart->next, *nextEnd = end->next;
                reverse(start, end);
                beforeStart->next = end;
                start->next = nextEnd;
                beforeStart = start;
                end = nextEnd;
            } else {
                end = end->next;
            }
            cnt++;
        }
        
        return dummy->next;
    }
};