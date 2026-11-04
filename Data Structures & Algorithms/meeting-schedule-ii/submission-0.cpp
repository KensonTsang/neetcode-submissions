/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        sort(intervals.begin(), intervals.end(), [] (const auto& lhs, const auto& rhs){
            return lhs.start < rhs.start;
        });


        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (const auto& interval : intervals) {
            
            if (minHeap.empty() || interval.start < minHeap.top()) {
                minHeap.push(interval.end);
            }
            else {
                minHeap.pop();
                minHeap.push(interval.end);
            }


        }

        return minHeap.size();
       
    }
};
