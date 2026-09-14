class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> hash{};
        queue<string>q{};

        for (auto& str : wordList) {
            hash.insert(str);
        }

        q.push(beginWord);
        int level = 0;

        while (q.size() > 0) {
            int size = q.size();

            for (int k = 0 ; k < size ; k++) {                  // by layer
                string str = q.front();
                q.pop();

                if (str == endWord) {
                    return level + 1;
                }
                
                string tempStr = str;

                for (int i = 0 ; i < str.size() ; i++) {        // loop character

                    for (char c = 'a' ; c <= 'z' ; c++) {
                        tempStr[i] = c;
                        if (hash.count(tempStr)) {
                            q.push(tempStr);
                            hash.erase(tempStr);
                        }
                    }

                    tempStr = str;                          // reset to ori character
                }
            }            

            level++;

        }

        
        return 0;
    }
};
