class Solution {
public:

    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, queue<pair<int, int>>& q) {

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int area = 1;

        while (q.size() > 0) {
            int y = q.front().first;
            int x = q.front().second;
            
            q.pop();
            
            for (int i = 0 ; i < dir.size() ; i++) {
                int ny = y + dir[i].first;
                int nx = x + dir[i].second;

                if (ny < 0 || ny >= grid.size() ||
                    nx < 0 || nx >= grid[0].size() ||
                    visited[ny][nx] ||
                    grid[ny][nx] == 0) {
                        continue;
                }

                visited[ny][nx] = true;
                q.push({ny,nx});
                area++;
            }

        }

        return area;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int ROW = grid.size();
        int COL = grid[0].size();

        vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
        queue<pair<int, int>> q{};

        int result = 0;

        for (int y = 0 ; y < ROW ; y++) {
            for (int x = 0 ; x < COL ; x++) {

                if (visited[y][x] || 
                    grid[y][x] == 0) {
                    continue;
                }

                visited[y][x] = true;
                q.push({y, x});

                int area = bfs(grid, visited, q);
                result = max(area, result);
            }
        }

        return result;

    }
};
