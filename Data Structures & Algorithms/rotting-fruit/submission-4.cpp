class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Count fresh oranges and store rotten oranges
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }

                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0)
            return 0;

        int minutes = 0;

        int dir[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {

                pair<int, int> curr = q.front(); // front(), not first()
                q.pop();                         // pop() returns void

                int r = curr.first;
                int c = curr.second;

                for (int k = 0; k < 4; k++) {
                    int nr = r + dir[k][0];
                    int nc = c + dir[k][1];

                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                        continue;

                    if (grid[nr][nc] != 1)
                        continue;

                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr, nc});
                }
            }

            minutes++;
        }

        if (fresh == 0)
            return minutes - 1;

        return -1;
    }
};


