class Solution {
public:

    string encode(vector<string>& strs) {
        string result;

        stringstream ss;
        
        for (const auto& str : strs) {
            ss << str.size();
            ss << "#";
            ss << str;
        }

        result = ss.str();        

        return result;
    }

    vector<string> decode(string s) {
       
        vector<string> result;

        for (int i = 0 ; i < s.size() ;) {
            int strLength = 0;
            while (s[i] != '#') {
                strLength *= 10;
                strLength += (s[i] - '0');
                i++;
            }
            
            i++;

            result.push_back(s.substr(i, strLength));
            i += strLength;    
        }

        return result;

    }
};
