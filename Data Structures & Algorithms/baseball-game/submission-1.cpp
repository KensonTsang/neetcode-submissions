class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        stack<int> st;

        for (int i = 0 ; i < operations.size() ; i++) {
            string s = operations[i];

            if (s == "+") {
                int stPrev1 = st.top();
                st.pop();
                int stPrev2 = st.top();
                st.pop();

                int addNum = stPrev1 + stPrev2;
                st.push(stPrev2);
                st.push(stPrev1);
                st.push(addNum);
            }
            else if (s == "C") {
                st.pop();
            }
            else if (s == "D") {
                int doubleScore = st.top() * 2;
                st.push(doubleScore);
            }
            else {
                st.push(stoi(s));
            }

        }

        int result = 0;
        while (st.size() > 0){
            result += st.top();
            st.pop();
        }
        
        return result;

    }
};