class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int , double>> p{};     // <int, time to the target>

        for (int i = 0; i < position.size() ; i++) {
            double timeToTarget = (double)(target - position[i]) / speed[i];         // speed[i];
            p.push_back({position[i], timeToTarget});       
        }

        sort(p.begin(), p.end());            // sort to p by first element


        int result = 0;
        double curLeadingTime = 0;

        for (int i = p.size() - 1; i >= 0 ; --i) {
            if (p[i].second > curLeadingTime) {
                result++;
                curLeadingTime = p[i].second;
            }
        }


        return result;


        
    }
};
