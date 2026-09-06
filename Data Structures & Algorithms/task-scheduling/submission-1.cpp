class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskMap{};

        for (char c : tasks) {
            taskMap[c]++;               // count the num
        }

        priority_queue<int> pq{};
        for (const auto& element : taskMap) {
            pq.push(element.second);    // push how many task need to be execute
        }

        int result = 0;
        queue<pair<int, int>> q{};      // number of task execute & target cool down time
        while (pq.size() > 0 || q.size() > 0) {
            
            result++;

            if (q.size () > 0) {        // check cool down has been completed
                auto element = q.front();
                if (element.second <= result) {
                    q.pop();
                    pq.push(element.first);
                }
            }

            if (pq.size() > 0) {        // execute the task and push it into the cooldown list
                int taskRemain = pq.top() - 1;
                pq.pop();
                if (taskRemain > 0) {
                    q.push({taskRemain, result + n + 1});
                }
            }


        }


        return result;

    }
};
