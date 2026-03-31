class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stringStack{};
        unordered_set<string> validOperator{"+", "-", "*", "/"};

        for(auto& token : tokens) {
            if (validOperator.find(token) != validOperator.end()) {
                int pop1 = stoi(stringStack.top());
                stringStack.pop();
                int pop2 = stoi(stringStack.top());
                stringStack.pop();
                int answer = 0;

                if (token == "+"){
                    answer = pop2 + pop1;
                }   
                else if (token == "-") {
                    answer = pop2 - pop1;
                }   
                else if (token == "*") {
                    answer = pop2 * pop1;
                }   
                else if (token == "/") {
                    answer = pop2 / pop1;
                }   
                stringStack.push(to_string(answer));
            }
            else {
                stringStack.push(token);
            }
        }


        return stoi(stringStack.top());

    }
};
