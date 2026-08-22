class Solution {
public:

    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, vector<vector<bool>>& flow, queue<pair<int, int>>& q) {

        int ROW = heights.size();
        int COL = heights[0].size();

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0 ,1}};

        while (q.size() > 0) {

            auto top = q.front();
            q.pop();

            for (int i = 0 ; i < dir.size() ; i++) {
                
                int ny = top.first + dir[i].first;
                int nx = top.second + dir[i].second;

                if (ny < 0 || ny >= ROW ||
                    nx < 0 || nx >= COL ||
                    visited[ny][nx] ||
                    heights[top.first][top.second] > heights[ny][nx]) {
                        continue;
                }

                visited[ny][nx] = true;
                flow[ny][nx] = true;
                q.push({ny, nx});
            }

        }


    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacificFlow (heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> pacificVisited (heights.size(), vector<bool>(heights[0].size(), false));

        vector<vector<bool>> atlanticFlow (heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlanticVisited(heights.size(), vector<bool>(heights[0].size(), false));

        queue<pair<int, int>> q{};  // y, x

        int ROW = heights.size();
        int COL = heights[0].size();
       

        // [0][x++]
        for (int i = 0 ; i < heights[0].size() ; i++) {
            
            if (pacificVisited[0][i]) {
                continue;
            }

            pacificFlow[0][i] = true;
            pacificVisited[0][i] = true;
            q.push({0, i});
            bfs(heights, pacificVisited, pacificFlow, q);
        }


        // [y++][0]
        for (int i = 0 ; i < heights.size() ; i++) {
            
            if (pacificVisited[i][0]) {
                continue;
            }

            pacificFlow[i][0] = true;
            pacificVisited[i][0] = true;
            q.push({i, 0});
            bfs(heights, pacificVisited, pacificFlow, q);
        }


        int LAST_ROW = ROW - 1;
        int LAST_COL = COL - 1;
        
        // [last_row][x++]
        for (int i = 0 ; i < heights[LAST_ROW].size() ; i++) {
            
            if (atlanticVisited[LAST_ROW][i]) {
                continue;
            }

            atlanticFlow[LAST_ROW][i] = true;         
            atlanticVisited[LAST_ROW][i] = true;         
            q.push({LAST_ROW, i});
            bfs(heights, atlanticVisited, atlanticFlow, q);
        }

        
        // [y++][LAST_COL]
        for (int i = 0 ; i < heights.size() ; i++) {
            
            if (atlanticVisited[i][LAST_COL]) {
                continue;
            }

            atlanticFlow[i][LAST_COL] = true;
            atlanticVisited[i][LAST_COL] = true;
            q.push({i, LAST_COL});
            bfs(heights, atlanticVisited, atlanticFlow, q);
        }


        vector<vector<int>> result{};

        for(int y = 0 ; y < ROW ; y++) {
            for (int x = 0 ; x < COL ; x++) {            
                if (pacificFlow[y][x] && atlanticFlow[y][x]) {
                    result.push_back({y, x});
                }
            }
        }

        return result;

    }
};
