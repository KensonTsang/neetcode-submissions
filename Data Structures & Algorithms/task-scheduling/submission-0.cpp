class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> freq{};
        for (const auto& c : tasks) {   //freq
            freq[c]++;
        }

        priority_queue<int> pq{};
        for (const auto& element : freq) {  
            pq.push(element.second);    // task can be execute
        }


        int result = 0;
        queue<pair<int, int>> q{};      // task is cooling down
        while (pq.size() > 0 || q.size() > 0) {
            result++;

            if (q.size() > 0 && q.front().second <= result) {
                pq.push(q.front().first);
                q.pop();
            }

            if (pq.size() > 0) {
                int t = pq.top();
                pq.pop();
                t -= 1;

                if (t > 0) {
                    q.push({t, result + n + 1});
                }                
            }

        }

        return result;


    }
};
