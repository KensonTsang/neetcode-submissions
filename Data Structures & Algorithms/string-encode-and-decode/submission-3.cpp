class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for(string& str : strs) {
            result += to_string(str.length()) + "#" + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int charPointer = 0;
        while(charPointer < s.length()) {
            int strSize = 0;            
            while (s[charPointer] != '#') {
                strSize = (strSize * 10) + int(s[charPointer] - '0');
                charPointer++;                
            }
            
            charPointer++;

            string tempStr;
            tempStr.reserve(strSize);
            int targetStrPointer = charPointer + strSize;
            while(charPointer < targetStrPointer) {
                tempStr += s[charPointer];
                charPointer++;
            }
            result.push_back(tempStr);
        }

        return result;
    }
};
