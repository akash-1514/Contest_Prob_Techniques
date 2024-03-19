class Node {
public:
    string val;
    Node* prev;
    Node* next;
    
    Node(string v) {
        val = v,
        prev = NULL;
        next = NULL;
    }
};
class BrowserHistory {
public:
    Node* head, *curr = NULL;
    BrowserHistory(string homepage) {
        head = new Node(homepage);
        curr = head;
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        curr->next = newNode;
        newNode->prev = curr;
        curr = curr->next;
    }
    
    string back(int steps) {
        int cnt = 1;
        while(curr->prev != NULL && cnt <= steps) {
            curr = curr->prev;
            cnt++;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        int cnt = 1;
        while(curr->next != NULL && cnt <= steps) {
            curr = curr->next;
            cnt++;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */