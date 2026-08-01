class Solution {
public:
    void dfs(vector<vector<int>>& heights,
             vector<vector<bool>>& visited,
             int r,
             int c) {

        int rows = heights.size();
        int cols = heights[0].size();

        visited[r][c] = true;

        int dir[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        for (int k = 0; k < 4; k++) {
            int nr = r + dir[k][0];
            int nc = c + dir[k][1];

            // Boundary check
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                continue;

            // Already visited
            if (visited[nr][nc])
                continue;

            // Reverse DFS: move only to equal or higher height
            if (heights[nr][nc] < heights[r][c])
                continue;

            dfs(heights, visited, nr, nc);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        // Pacific (left border)
        for (int i = 0; i < rows; i++) {
            dfs(heights, pacific, i, 0);
        }

        // Pacific (top border)
        for (int j = 0; j < cols; j++) {
            dfs(heights, pacific, 0, j);
        }

        // Atlantic (right border)
        for (int i = 0; i < rows; i++) {
            dfs(heights, atlantic, i, cols - 1);
        }

        // Atlantic (bottom border)
        for (int j = 0; j < cols; j++) {
            dfs(heights, atlantic, rows - 1, j);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};