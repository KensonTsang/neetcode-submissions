class Solution {
public:

    bool dfs (int row, int col, int i, string& word, vector<vector<char>>& board, vector<vector<bool>>& visited) {

        if (row < 0 ||
            col < 0 ||
            row >= board.size() ||
            col >= board[0].size() ||
            visited[row][col] ||
            word[i] != board[row][col]) {
                return false;
            }

        if (i == word.size() - 1 && 
            word[i] == board[row][col]) {
                return true;
            }

        visited[row][col] = true;

        bool found = dfs(row + 1, col, i + 1, word, board, visited) ||
                    dfs(row - 1, col, i + 1, word, board, visited)  ||
                    dfs(row, col + 1, i + 1, word, board, visited)  ||
                    dfs(row, col - 1, i + 1, word, board, visited);

        visited[row][col] = false;

        return found;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int y = 0; y < row ; y++) {
            for (int x = 0 ; x < col ; x++) {
                if (word[0] == board[y][x] && 
                    dfs(y, x, 0, word, board, visited)) {
                    return true;
                }
            }
        }

        return false;

    }
};
