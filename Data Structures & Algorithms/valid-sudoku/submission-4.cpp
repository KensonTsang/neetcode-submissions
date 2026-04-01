class Solution {
public:

    bool isValidRow(vector<vector<char>>& board, int startYIndex) {
        bool index[10] = {false};
        for(int x = 0; x < 9; ++x) {
            auto val = board[startYIndex][x];
            auto i = val - '0';
            if (val != '.') {
                if (index[i]) {
                    return false;
                }
                index[i] = true;
            }
        }        
        return true;        
    }

    bool isValidCol(vector<vector<char>>& board, int startXIndex) {
        bool index[10] = {false};
        for(int y = 0; y < 9; ++y) {
            auto val = board[y][startXIndex];
            auto i = val - '0';
            if (val != '.') {
                if (index[i]) {
                    return false;
                }
                index[i] = true;
            }
        }        
        return true;
    }

    bool isValid9x9Block(vector<vector<char>>& board, int startIndexY, int startIndexX) {
        bool index[10] = {false};
        for(int y = 0; y < 3; ++y) {
            for (int x = 0; x < 3; ++x) {
                auto val = board[y + startIndexY][x + startIndexX];
                auto i = val - '0';
                if (val != '.') {
                    if (index[i]) {
                        return false;
                    }                    
                    index[i] = true;
                }                
            }            
        }                
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i) {
            if (!isValidRow(board, i)) return false;
            if (!isValidCol(board, i)) return false;
        }

        for (int y = 0 ; y < 9 ; y+=3) {
            for (int x = 0 ; x < 9 ; x+=3) {
                if (!isValid9x9Block(board, y ,x)) return false;
            }
        }

        return true;
    }
};
