class Solution {
public:

    void bfs (vector<vector<char>>& board, queue<pair<int, int>>& q, vector<vector<bool>>& edgeRegion) {

        int ROW = board.size();
        int COL = board[0].size();

        vector<pair<int, int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while(q.size() > 0) {

            auto top = q.front();
            q.pop();
            int y = top.first;
            int x = top.second;

            for (int i = 0 ; i < dir.size() ; i++) {
                int ny = y + dir[i].first;
                int nx = x + dir[i].second;

                if (ny < 0 || ny >= ROW ||
                    nx < 0 || nx >= COL ||
                    edgeRegion[ny][nx] ||
                    board[ny][nx] == 'X') {
                        continue;
                    }

                    edgeRegion[ny][nx] = true;
                    q.push({ny, nx});
            }

        }


    }


    void solve(vector<vector<char>>& board) {
        
        int ROW = board.size();
        int COL = board[0].size();

        vector<vector<bool>> edgeRegion(ROW, vector<bool>(COL, false));
        queue<pair<int, int>> q{};

        vector<int> EDGE_ROWS = {0, ROW - 1};
        vector<int> EDGE_COLS = {0, COL - 1};

        for (auto y : EDGE_ROWS){
            for (int x = 0 ; x < COL ; x++) {

                if (board[y][x] == 'X' ||
                    edgeRegion[y][x]) {
                        continue;
                }

                // board[y][x] == "O" and edgeRegion not marked yet

                edgeRegion[y][x] = true;
                q.push({y, x});
            }
        }

        for (int y = 0 ; y < ROW ; y++) {
            for (auto x : EDGE_COLS) {

                if (board[y][x] == 'X' ||
                    edgeRegion[y][x]) {
                        continue;
                }

                // board[y][x] == "O" and edgeRegion not marked yet

                edgeRegion[y][x] = true;
                q.push({y, x});
            }
        }
        
        bfs(board, q, edgeRegion);


        for (int y = 0 ; y < ROW ; y++) {
            for (int x = 0 ; x < COL ; x++) {
                if (!edgeRegion[y][x]) {
                    board[y][x] = 'X';
                }
            }
        }
        

    }
};
