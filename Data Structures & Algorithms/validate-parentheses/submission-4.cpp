class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mapping{};
        mapping['('] = ')';
        mapping['['] = ']';
        mapping['{'] = '}';

        stack<char> st{};

        for (auto c : s) {
            
            if (mapping.count(c)) { // open bracket
                st.push(mapping[c]);
            }
            else if (st.size() > 0 && st.top() == c) {                  // close bracket                
                st.pop();                             
            }
            else {
                return false;
            }

        }

        return st.size() == 0;
    }
};
