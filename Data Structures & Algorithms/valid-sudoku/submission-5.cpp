class Solution {
public:

    bool isValidRow(vector<vector<char>>& board, int y) {
        vector<bool> isContainNum (9, false);

        for (int i = 0 ; i < 9 ; ++i) {
            char c = board[y][i];
            if (c == '.') continue;

            int indexC = c - '1';
            if (isContainNum[indexC]) return false;

            isContainNum[indexC] = true;
        }

        return true;

    }

    bool isValidCol(vector<vector<char>>& board, int x) {
        vector<bool> isContainNum (9, false);

        for (int i = 0 ; i < 9 ; ++i) {
            char c = board[i][x];
            if (c == '.') continue;

            int indexC = c - '1';
            if (isContainNum[indexC]) return false;

            isContainNum[indexC] = true;
        }

        return true;
    }

    bool isValid3x3(vector<vector<char>>& board, int x, int y) {
        
        vector<bool> isContainNum (9, false);

        for (int y1 = 0 ; y1 < 3 ; y1++) {
            for (int x1 = 0 ; x1 < 3 ; x1++) {
                char c = board[y + y1][x + x1];
                if (c == '.') continue;

                int indexC = c - '1';
                if (isContainNum[indexC]) return false;

                isContainNum[indexC] = true;
            }
        }
        return true;
    }


    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0 ; i < 9 ; ++i) {
            if (!isValidCol(board, i) || !isValidRow(board, i)) return false;
        }


        for (int y = 0 ; y < 3 ; ++y) {
            for (int x = 0 ; x < 3 ; ++x) {
                if (!isValid3x3(board, x * 3, y * 3)) return false;
            }
        }
        

        return true;

    }
};
