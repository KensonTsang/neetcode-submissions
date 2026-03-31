class Solution {
public:
    bool isValid(string s) {
        stack<char> closeStack{};
        unordered_map<char, char> closePair{
                                    {'{','}'},
                                    {'[',']'},
                                    {'(',')'}};

        for(char c : s) {
            if (closePair.find(c) != closePair.end()) {
                closeStack.push(closePair[c]);
            }
            else if (closeStack.size() > 0 && closeStack.top() == c) {
                closeStack.pop();
            }                
            else {
                return false;
            }
            
        }

        return closeStack.size() == 0;
    }
};
