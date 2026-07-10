class Solution {
public:

    bool dfs (int row, int col, int i, string& word, vector<vector<char>>& board, set<pair<int, int>>& foundIndices) {

        if (row < 0 ||
            col < 0 ||
            row >= board.size() ||
            col >= board[0].size() ||
            foundIndices.count({row, col}) ||
            word[i] != board[row][col]) {
                return false;
            }

        if (i == word.size() - 1 && 
            word[i] == board[row][col]) {
                return true;
            }

        foundIndices.insert({row, col});

        bool found = dfs(row + 1, col, i + 1, word, board, foundIndices) ||
                    dfs(row - 1, col, i + 1, word, board, foundIndices)  ||
                    dfs(row, col + 1, i + 1, word, board, foundIndices)  ||
                    dfs(row, col - 1, i + 1, word, board, foundIndices);

        foundIndices.erase({row, col});

        return found;

    }


    bool exist(vector<vector<char>>& board, string word) {
        
        int row = board.size();
        int col = board[0].size();
        set<pair<int, int>> foundIndices{};

        for (int y = 0; y < row ; y++) {
            for (int x = 0 ; x < col ; x++) {
                if (word[0] == board[y][x] && 
                    dfs(y, x, 0, word, board, foundIndices)) {
                    return true;
                }
            }
        }

        return false;

    }
};
