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
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        if (intervals.size() <= 0) {
            return true;
        }

        sort(intervals.begin(), intervals.end(), [](const auto& lhr, const auto& rhs) {
            return lhr.start < rhs.start;
        });

        int prevEnd = intervals.front().end;

        for (int i = 1 ; i < intervals.size() ; ++i) {

            int start = intervals[i].start;
            int end = intervals[i].end;

            if (start < prevEnd) {
                return false;
            }
            
            prevEnd = end;

        }

        return true;

    }
};
