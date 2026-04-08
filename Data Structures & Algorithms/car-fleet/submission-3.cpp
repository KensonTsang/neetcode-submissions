class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> timeToTarget;

        for(int i = 0 ; i < position.size() ; i++) {
            double t = (double)(target - position[i]) / speed[i];
            timeToTarget.push_back({position[i], t});
        }

        sort(timeToTarget.begin(), timeToTarget.end());
        
        double headOfTime = 0;
        int numOfCarFleet = 0;

        for (int i = position.size() - 1 ; i >= 0; i--) {
            if (timeToTarget[i].second > headOfTime) {
                headOfTime = timeToTarget[i].second;
                numOfCarFleet++;
            }
        }

        return numOfCarFleet;


    }
};
