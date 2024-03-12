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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*>mp;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int currSum = 0;
        mp[0] = dummy;
        
        ListNode* curr = head;
        while(curr != NULL) {
            currSum += curr->val;
            if(mp.find(currSum) != mp.end()) {
                curr = mp[currSum]->next;
                int prefix = currSum;
                while((prefix + curr->val) != currSum) { 
                    mp.erase(prefix + curr->val);
                    prefix += curr->val;
                    curr = curr->next;
                }
                mp[currSum]->next = curr->next;
            } else {
                mp[currSum] = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};