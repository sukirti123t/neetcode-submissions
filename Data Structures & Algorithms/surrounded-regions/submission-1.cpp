class Solution {
public:
    int rows, cols;

    void dfs(vector<vector<char>>& board, int r, int c) {
        // Mark current cell as safe
        board[r][c] = 'T';

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

            // Skip if not an unvisited 'O'
            if (board[nr][nc] != 'O')
                continue;

            dfs(board, nr, nc);
        }
    }

    void solve(vector<vector<char>>& board) {

        rows = board.size();
        cols = board[0].size();

        // Top row
        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j);
        }

        // Bottom row
        for (int j = 0; j < cols; j++) {
            if (board[rows - 1][j] == 'O')
                dfs(board, rows - 1, j);
        }

        // Left column
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
        }

        // Right column
        for (int i = 0; i < rows; i++) {
            if (board[i][cols - 1] == 'O')
                dfs(board, i, cols - 1);
        }

        // Convert surrounded regions
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                else if (board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
};