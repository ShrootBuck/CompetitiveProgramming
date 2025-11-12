class Solution {
  public:
    void bfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited, int m,
             int n) {
        // Check if the current cell is out of bounds, already visited, or water
        if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] || grid[r][c] == '0') {
            return;
        }

        visited[r][c] = true;

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        // yummy O(1) pops
        queue<pair<int, int>> q;
        q.push({r, c});

        while (!q.empty()) {
            auto [curr_r, curr_c] = q.front();
            q.pop();

            // all four directions
            for (int i = 0; i < 4; i++) {
                int new_r = curr_r + dr[i];
                int new_c = curr_c + dc[i];

                // Check if the new cell is valid, unvisited, and land
                if (new_r >= 0 && new_r < m && new_c >= 0 && new_c < n && !visited[new_r][new_c] &&
                    grid[new_r][new_c] == '1') {
                    visited[new_r][new_c] = true;
                    q.push({new_r, new_c});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        vector<vector<bool>> visited(m, vector<bool>(n));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == '1' && !visited[r][c]) {
                    islands++;
                    bfs(r, c, grid, visited, m, n);
                }
            }
        }

        return islands;
    }
};
