class Solution {
public:

    class TriesNode {
    public:
        unordered_map<char, TriesNode*> children;
        string str;
    };

    TriesNode root;
    vector<vector<bool>> visit;
    vector<string> result;


    void dfs(int row, int col, vector<vector<char>>& board, TriesNode* cur) {
        if (row >= board.size() ||
            col >= board[0].size() ||
            row < 0 ||
            col < 0 ||
            visit[row][col] ||
            !cur->children.count(board[row][col])) {    // the tries not exist the character
            return;
        }


        visit[row][col] = true;        
        cur = cur->children[board[row][col]];

        
        if (cur->str.size() > 0) {
            result.push_back(cur->str);
            cur->str.clear();          // this push_back condition would only run once, prevent cat(add) -> catt(add)            
        }


        dfs (row + 1, col, board, cur);
        dfs (row - 1, col, board, cur);
        dfs (row, col + 1, board, cur);
        dfs (row, col - 1, board, cur);

        visit[row][col] = false;

    }



    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        visit.assign(board.size(), vector<bool>(board[0].size(), false));

        for (auto& word : words) {
            auto* cur = &root;
            for (auto c : word) {
                if (!cur->children.count(c)) {
                    cur->children[c] = new TriesNode();
                }
                cur = cur->children[c];
            }
            cur->str = word;
        }


        for (int r = 0; r < board.size() ; r++) {
            for (int c = 0 ; c < board[0].size() ; c++) {
                dfs(r, c, board, &root);
            }
        }

        return result;

    }
};
