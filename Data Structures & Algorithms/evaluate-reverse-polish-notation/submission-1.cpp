class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        unordered_set<string> op = {"+", "-", "*", "/"};
        stack<int> st{};


        for (const auto& token : tokens) {

            if (op.count(token)) {          // operator
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                
                if (token == "+") {
                    st.push(num1 + num2);
                }
                else if (token == "-") {
                    st.push(num1 - num2);
                }
                else if (token == "*") {
                    st.push(num1 * num2);
                }
                else if (token == "/"){
                    st.push(num1 / num2);
                }
            }
            else {                          // number
                int num = stoi(token);     
                st.push(num);
            }
        }

        return st.top();

    }
};
