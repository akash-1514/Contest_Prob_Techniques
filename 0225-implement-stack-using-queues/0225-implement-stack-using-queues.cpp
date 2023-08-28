class MyStack {
public:
    vector<int>arr;
    int Top;
    MyStack() {
        Top = -1;
        arr.resize(1000001);
    }
    
    void push(int x) {
        if(Top == 1000000) {
            return;
        }
        Top++;
        arr[Top] = x;
    }
    
    int pop() {
        if(Top == -1) {
            return -1;
        }
        int x = arr[Top];
        Top--;
        return x;
    }
    
    int top() {
        if(Top == -1) {
            return -1;
        }
        return arr[Top];
    }
    
    bool empty() {
        return Top == -1;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */