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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start = NULL, *end = NULL, *curr = list1;
        int cnt = 1;
        while(curr != NULL) {
            if(cnt == a) {
                start = curr;
            } else if(cnt == b + 1) {
                end = curr;
                break;
            }
            cnt++;
            curr = curr->next;
        }
        
        ListNode* temp = list2;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        
        temp->next = end->next;
        
        start->next = list2;
        return list1;
    }
};