class Solution {
public:

    void bfs(vector<vector<char>>& grid, queue<pair<int, int>>& q, vector<vector<bool>>& visited) {

        vector<pair<int, int>> dir = { {-1,0}, {1,0}, {0,-1}, {0,1}};

        while(q.size() > 0) {

            auto top = q.front();
            q.pop();

            for (int i = 0 ; i < dir.size() ; i++) {

                int newY = top.first + dir[i].first;
                int newX = top.second + dir[i].second;

                if (newY < 0 || newY >= grid.size() ||
                    newX < 0 || newX >= grid[0].size() ||
                    visited[newY][newX]) {
                        continue;
                }

                visited[newY][newX] = true;

                if (grid[newY][newX] == '1') {
                    q.push({newY, newX});
                }
                
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        
        vector<vector<bool>> visited (
            grid.size(), vector<bool>(
                grid[0].size(), false
            )
        );

        int col = grid.size();
        int row = grid[0].size();

        queue<pair<int, int>> q{};  // y, x

        int island = 0;

        for (int y = 0 ; y < col ; y++){
            for (int x = 0 ; x < row ; x++) {
                if (visited[y][x]){
                    continue;
                }

                visited[y][x] = true;

                if (grid[y][x] == '1') {
                    island++;
                    q.push({y, x});
                    bfs(grid, q, visited);
                }
                
            }
        }

        return island;

    }
};
