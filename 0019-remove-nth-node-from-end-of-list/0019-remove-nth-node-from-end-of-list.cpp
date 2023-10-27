class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode * curr = head ; 
       ListNode* temp = head;

        int cnt = 0 ; 
        int cnt1 = 0 ;
        while (curr!=NULL)
        {
            cnt++;
            curr = curr->next;
        }
        int ans = cnt-n;
        if(ans==0)
        {
//             ListNode * head1 = head->next;
            
//             temp->next = head1;
//             temp = temp->next;
            return head->next;
            // return temp;
            
        }
        while (cnt1<ans-1)
        {
            
            temp = temp->next;
            cnt1++;
        }
        cout << temp->val << endl;
        // if(cnt1>=cnt-1)
        // {
             temp->next = temp->next->next ;
        // }
        
        // return temp ;
        return head;
    }
};