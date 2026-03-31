class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> timeToTarget{};
        for (int i = 0 ; i < position.size() ; i++) {
            double time = (double)(target - position[i]) / speed[i];
            timeToTarget.push_back({position[i], time});
        }

        sort(timeToTarget.begin(), timeToTarget.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
            return a.first > b.first;
        });

        int fleetNum = 0;
        double maxTime = 0;
        for (auto& p : timeToTarget) {
            if (p.second > maxTime) {
                maxTime = p.second;
                fleetNum++;
            }
        }

        return fleetNum;
    }
};
