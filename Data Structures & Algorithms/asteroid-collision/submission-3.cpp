class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       
        stack<int> st{}; 

        for (int i = 0 ; i < asteroids.size() ; i++) {
            
            if (st.size() == 0 || asteroids[i] > 0) {
                st.push(asteroids[i]);
                continue;
            }

            int absValue = abs(asteroids[i]);
            while (true) {
                if (st.size() == 0) {
                    st.push(asteroids[i]);
                    break;
                } else if (st.top() < 0) {
                    st.push(asteroids[i]);
                    break;
                }
                else if (st.top() == absValue) {
                    st.pop();
                    break;
                }
                else if (st.top() > absValue) {
                    break;
                }
                else {
                    st.pop();
                }
            }

        }


        vector<int> result(st.size(), 0);
        int i = result.size() - 1;
        while (st.size() > 0) {
            result[i] = st.top();
            st.pop();
            --i;
        }

        return result;



    }
};