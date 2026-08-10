class Solution {
private:

    priority_queue<int> pq;

public:
    int lastStoneWeight(vector<int>& stones) {
        
        for (int num : stones) {
            pq.push(num);
        }

        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();

            int y = pq.top();
            pq.pop();

            if (x == y) {
                continue;
            }

            if (x > y) {
                x = x - y;
                pq.push(x);
            } else {
                y = y - x;
                pq.push(y);
            }
        }

        
        return pq.size() > 0 ? pq.top() : 0;

    }
};
