class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int col = grid.size();
        int row = grid[0].size();

        queue<pair<int, int>> q{};
        vector<vector<bool>> visited (grid.size(), vector<bool>(grid[0].size(), false));

        for (int y = 0 ; y < col ; ++y) {
            for (int x = 0 ; x < row ; ++x) {
                if(grid[y][x] == 0) {
                    q.push({y,x});          // adding all the treasure into the queue (start with 0 distance)
                    visited[y][x] = true;                                
                }
            }
        }

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        

        while(q.size() > 0) {
            auto topY = q.front().first;
            auto topX = q.front().second;
            q.pop();

            for (int i = 0 ; i < dir.size() ; ++i) {
                int newY = topY + dir[i].first;
                int newX = topX + dir[i].second;

                if (newY < 0 || newY >= grid.size() ||        // boundary
                    newX < 0 || newX >= grid[0].size() ||     // boundary
                    visited[newY][newX] ||                  // visited
                    grid[newY][newX] == -1){                 // water

                    continue;
                }

                visited[newY][newX] = true;
                grid[newY][newX] = grid[topY][topX] + 1;
                q.push({newY, newX});

            }
        }
        
    }
};
