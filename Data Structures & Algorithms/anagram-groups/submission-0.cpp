class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapping{};

        for (const auto& str : strs) {
            string sortedWord = str;
            sort(sortedWord.begin(), sortedWord.end());

            mapping[sortedWord].push_back(str);
        }

        vector<vector<string>> result{};
        for (const auto& entry : mapping) {
            result.push_back(entry.second);
        }

        return result;


    }
};
