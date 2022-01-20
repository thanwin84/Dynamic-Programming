
 class Solution {
public:
    int total_path;
    void solve(vector<vector<int>>& grid, vector<vector<int>>& visited, int r, int c) {
        if (r == 0 and c == 0) {
            total_path += 1;
            return;
        }
        //up
        if (r - 1 >= 0 and visited[r - 1][c] != -1 and grid[r - 1][c] == 0) {
            visited[r][c] = -1;
            solve(grid, visited, r -1, c);
            visited[r][c] = 0;
        }
        if (c - 1 >= 0 and visited[r][c - 1] != -1 and grid[r][c - 1] == 0) {
            visited[r][c] = -1;
            solve(grid, visited, r, c - 1);
            visited[r][c] = 0;
        }
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        if (obstacleGrid[r - 1][c - 1] == 1){
            return 0;
        }
        total_path = 0;
        vector<vector<int>> visited(r, vector<int>(c, 0));
        solve(obstacleGrid, visited, r - 1, c - 1);
  
        return total_path;
    }
};
//time: O(2^r + c) since we have two choice every step
//algo: Backtracking
space: O(r+c)
