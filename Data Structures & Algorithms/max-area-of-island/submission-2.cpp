class Solution {
public:

    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, queue<pair<int, int>>& q) {

        int landCount = 1;

        while (q.size() > 0) {

            auto top = q.front();
            q.pop();

            for (int i = 0 ; i < dir.size() ; ++i) {

                int ny = top.first + dir[i].first;
                int nx = top.second + dir[i].second;

                if (ny < 0 || ny >= grid.size() ||
                    nx < 0 || nx >= grid[0].size() ||
                    visited[ny][nx]) {
                        continue;
                }


                visited[ny][nx] = true;

                if (grid[ny][nx] == 1) {
                    q.push({ny, nx});
                    landCount++;                    
                }

            }


        }

        return landCount;

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        vector<vector<bool>> visited (grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> q{};

        int result = 0;

        int col = grid.size();
        int row = grid[0].size();

        for (int y = 0 ; y < col ; ++y) {
            for (int x = 0 ; x < row ; ++x) {

                if (visited[y][x])
                    continue;

                visited[y][x] = true;
                if (grid[y][x] == 1) {                    
                    q.push({y, x});
                    int area = bfs(grid, visited, q);
                    result = max(area, result);
                }



            }
        }

        return result;


    }
};
