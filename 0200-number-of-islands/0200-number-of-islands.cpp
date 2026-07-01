class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0')
            return;

        grid[i][j] = '0';   // Mark as visited

        dfs(i - 1, j, grid); // Up
        dfs(i + 1, j, grid); // Down
        dfs(i, j - 1, grid); // Left
        dfs(i, j + 1, grid); // Right
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1') {
                    islands++;
                    dfs(i, j, grid);
                }

            }
        }

        return islands;
    }
};