class CustomStack {
private:
    vector<int>vec;
    int size, idx;
    stack<int>st;
public:
    CustomStack(int maxSize) {
        vec.resize(maxSize, 0);
        size = maxSize;
        idx = 0;
    }
    
    void push(int x) {
        if(idx < size) {
            st.push(x);
            idx++;
        } else {
            return;
        }
    }
    
    int pop() {
        if(st.empty()) return -1;
        int topEle = st.top() + vec[idx - 1];
        if(idx - 1 > 0) {
            vec[idx - 2] += vec[idx - 1];
        }
        vec[idx - 1] = 0;
        st.pop();
        idx--;
        return topEle;
    }
    
    void increment(int k, int val) {
        if(idx == 0) return;
        vec[min(idx - 1, k - 1)] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */