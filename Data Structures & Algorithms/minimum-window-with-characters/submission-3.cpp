// "OUZODYXAZV", t = "XYZ"
// 
// 
// need: X:1, Y:1, Z:1
// 
// vaild (how many character has been verified, if vaild == need means all can start // substring)
// 
// 
// 2 map:
// 1: needmap
// 2: windowsmap
// 
// step1: filling the needmap, this is not change
// step2: sliding windows l,r start r and populate it to the windowsmap, if map[// c].count == needmap.count, it means the vailded c count has been reached.
// step3: if the vaild == need, that means can move the l pointer, if the prev_l // pointer is one of the needmap's element, valid should be reduced and windows[// l_prev_c] should be reduced. 
// 
// t : ABC
// S : ACVCBA
// 	^   ^  <- enter the while loop
// 	 ^  ^  <- exit the while loop
// 
//      ^   ^ <- enter the while loop
//       ^  ^
//        ^ ^ 
//         ^^ <- exit the while loop
// 


class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int> need{};
        unordered_map<char, int> window{};  // only store the character that appear in t

        for(auto& c : t) {
            need[c]++;
        }

        int l = 0;
        int validNeedCount = 0;

        int stringStartIndex = 0;
        int minSubStringLength = INT_MAX;

        for (auto r = 0; r < s.size() ; r++) {
            char c = s[r];            
            if (need.count(c)) {    // this character is a requried character
                window[c]++;
                if (window[c] == need[c]) {
                    validNeedCount++;
                }                
            }


            while (validNeedCount == need.size()) {  // all the requried character is completed
                if (r - l + 1 < minSubStringLength) {
                    stringStartIndex = l;
                    minSubStringLength = r - l + 1;
                }

                char prev_c = s[l];
                l++;

                if (need.count(prev_c)){
                    if (need[prev_c] == window[prev_c]) {
                       validNeedCount--; 
                    }
                    window[prev_c]--;
                }
            }
        }

        return minSubStringLength == INT_MAX ? "" : s.substr(stringStartIndex, minSubStringLength);
            

        
    }
};
