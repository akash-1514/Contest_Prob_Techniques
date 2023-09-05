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
        if(head == NULL) return NULL;
        unordered_map<Node*, Node*>mp;
        Node* curr = head;
        while(curr != NULL) {
            Node* newNode = new Node(curr->val);
            mp[curr] = newNode;
            curr = curr->next;
        }
        curr = head;
        while(curr != NULL) {
            if(curr->next != NULL) {
                mp[curr]->next = mp[curr->next];
            }
            
            if(curr->random != NULL) {
                mp[curr]->random = mp[curr->random];
            }
            
            curr = curr->next;
        }
        
        return mp[head];
    }
};