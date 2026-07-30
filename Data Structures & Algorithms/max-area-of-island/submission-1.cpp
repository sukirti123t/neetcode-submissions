class Solution {
public:

    int Max = 0;

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int count = 0;

                if (grid[i][j] == 1) {
                    count_island(grid, i, j, count);
                    Max = max(Max, count);
                }

            }
        }

        return Max;
    }

    void count_island(vector<vector<int>>& grid, int i, int j, int &count) {

        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return;

        grid[i][j] = 0;

        count++;

        count_island(grid, i - 1, j, count);
        count_island(grid, i + 1, j, count);
        count_island(grid, i, j - 1, count);
        count_island(grid, i, j + 1, count);
    }
};