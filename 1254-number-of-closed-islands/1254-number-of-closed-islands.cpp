class Solution {
public:
    int n, m;

    void bfs(int r, int c, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = row + dr[k];
                int nc = col + dc[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    grid[nr][nc] == 0) {

                    grid[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // Step 1: Remove boundary-connected land
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0)
                bfs(i, 0, grid);

            if (grid[i][m - 1] == 0)
                bfs(i, m - 1, grid);
        }

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 0)
                bfs(0, j, grid);

            if (grid[n - 1][j] == 0)
                bfs(n - 1, j, grid);
        }

        // Step 2: Count remaining islands
        int cnt = 0;

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 0) {
                    cnt++;
                    bfs(i, j, grid);
                }
            }
        }

        return cnt;
    }
};