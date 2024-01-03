class MedianFinder {
public:
    int cnt = 0;
    priority_queue<int, vector<int>, greater<int>>min_pq;
    priority_queue<int>max_pq;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        cnt++;
        if((max_pq.size() - min_pq.size()) == 1) {
            if(num >= max_pq.top()) {
                min_pq.push(num);
            } else {
                min_pq.push(max_pq.top());
                max_pq.pop();
                max_pq.push(num);
            }
        } else {
            if(min_pq.size() == 0 || (min_pq.top() >= num)) {
                max_pq.push(num);
            } else {
                max_pq.push(min_pq.top());
                min_pq.pop();
                min_pq.push(num);
            }
        }
    }
    
    double findMedian() {
        if(cnt % 2 != 0) {
            return max_pq.top();
        } else {
            int a = max_pq.top(), b = min_pq.top();
            return (a + b) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */