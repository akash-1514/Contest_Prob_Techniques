/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        Node* curr = head;
        while(curr != NULL) {
            Node* newNode = new Node(curr->val), *next = curr->next;
            curr->next = newNode;
            newNode->next = next;
            curr = curr->next->next;
        }
        
        curr = head;
        while(curr != NULL) {
            if(curr->random != NULL) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
    
        curr = head;
        Node* dummy = new Node(0), *dptr = dummy;
        while(curr != NULL) {
            Node* nxt = curr->next->next;
            dptr->next = curr->next;
            curr->next = nxt;
            dptr = dptr->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};