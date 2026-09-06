class MedianFinder {

    priority_queue<int, vector<int>, less<int>> smallHeap;          // max heap, (top) 5 > 4 > 3 > 2 > 1, return 5
    priority_queue<int, vector<int>, greater<int>> largeHeap;       // min heap, (top) 1 > 2 > 3 > 4 > 5, return 1

public:

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallHeap.push(num);

        if (largeHeap.size() > 0 && smallHeap.top() > largeHeap.top()) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }

        if (smallHeap.size() > largeHeap.size() + 1) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }

        if (largeHeap.size() > smallHeap.size() + 1) {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }

    }
    
    double findMedian() {
        if (smallHeap.size() == largeHeap.size()) {
            return (smallHeap.top() + largeHeap.top()) / 2.0;
        }
        else if (smallHeap.size() > largeHeap.size()){
            return smallHeap.top();
        }
        else {
            return largeHeap.top();
        }
    }
};
