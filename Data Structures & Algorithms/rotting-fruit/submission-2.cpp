class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int col = grid.size();
        int row = grid[0].size();

        vector<vector<bool>> visited(col, vector<bool>(row, false));
        queue<pair<int, vector<int>>> q;

        int freshCount = 0;

        for (int y = 0 ; y < col ; ++y) {
            for (int x = 0 ; x < row ; ++x) {
                if (grid[y][x] == 2) {
                    q.push({0, {y,x}});
                    visited[y][x] = true;
                }
                else if (grid[y][x] == 1) {
                    freshCount++;
                }
            }
        }

        vector<pair<int, int>> dir = {{-1, 0},{1, 0},{0, -1},{0, 1}};

        int time = 0;
        while (q.size() > 0) {
            
            int topY = q.front().second[0];   // y
            int topX = q.front().second[1];   // x

            time = max(time, q.front().first); // time

            q.pop();

            for (int i = 0 ; i < dir.size() ; ++i) {

                int nY = topY + dir[i].first;
                int nX = topX + dir[i].second;

                if (nY < 0 || nY >= col ||
                    nX < 0 || nX >= row ||
                    visited[nY][nX] ||
                    grid[nY][nX] != 1) {
                     continue;
                }
                
                visited[nY][nX] = true;
                freshCount--;

                q.push({time + 1, {nY, nX}});
            }
        }

        return freshCount > 0 ? -1 : time;
        
        


    }
};
