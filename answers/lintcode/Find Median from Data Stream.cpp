class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();
        while (min_heap.size() > max_heap.size() + 1) {
            int temp = min_heap.top();
            min_heap.pop();
            max_heap.push(temp);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (min_heap.size() > max_heap.size()) {
            return min_heap.top();
        }
        else {
            return (min_heap.top() + max_heap.top()) / 2.0;
        }
    }
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int> > min_heap;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
