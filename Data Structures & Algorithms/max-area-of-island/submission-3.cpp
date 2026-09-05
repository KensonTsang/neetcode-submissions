class Solution {
public:

    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, queue<pair<int, int>>& q) {

        int area = 1;

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (q.size() > 0) {
            auto top = q.front();
            q.pop();

            for (int i = 0 ; i < dir.size() ; i++) {
                int ny = top.first + dir[i].first;
                int nx = top.second + dir[i].second;

                if (ny < 0 || ny >= grid.size() ||
                    nx < 0 || nx >= grid[0].size() ||
                    visited[ny][nx] ||
                    grid[ny][nx] == 0) {
                        continue;
                }

                visited[ny][nx] = true;
                q.push({ny, nx});
                area += bfs(grid, visited, q);

            }

        }
        
        return area;


    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int ROW = grid.size();
        int COL = grid[0].size();
        int result = 0;

        vector<vector<bool>> visited (grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> q{};
        
        for (int y = 0 ; y < ROW ; y++) {
            for (int x = 0 ; x < COL ; x++) {

                if (visited[y][x]) {
                    continue;
                }

                if (grid[y][x] == 0) {
                    continue;
                }

                visited[y][x] = true;
                q.push({y,x});
                int area = bfs(grid, visited, q);
                result = max(result, area);                
            }
        }

        return result;


    }
};
