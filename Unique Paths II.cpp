
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
//space: O(r+c)

// *****top down********//
int dp[101][101];
class Solution {
public:
    int total_path;
    int solve(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || grid[r][c]){
            return 0;
        }
        if (r == 0 and c == 0) {
            return 1;
        }
        if (dp[r][c] != -1){
            return dp[r][c];
        }
        int left = solve(grid, r -1, c);
        int right = solve(grid, r, c - 1);
        return dp[r][c] = left + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        memset(dp, -1, sizeof(dp));
        if (obstacleGrid[r - 1][c - 1] == 1){
            return 0;
        }
        total_path = 0;
        return solve(obstacleGrid, r - 1, c - 1);
    }
};
//time: O(n * m) and space: O(n + m)

// *****iterative********//
int dp[101][101];
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                dp[i][j] = 0;
                if (i == 0 and j == 0 and obstacleGrid[i][j] == 0){
                    dp[i][j] = 1;
                }
                else if (obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else {
                   if (j > 0){
                       dp[i][j] += dp[i][j - 1];
                   }
                   if (i > 0) {
                       dp[i][j] += dp[i - 1][j];
                   }
            }
        }
        }
        return dp[r - 1][c - 1];
    }
};
//time: O(n * m) and space: O(n + m)
// if we look closely, we can do it in constant time.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                if (i == 0 and j == 0 and obstacleGrid[i][j] == 0){
                    obstacleGrid[i][j] = 1;
                }
                else if (obstacleGrid[i][j] == 1){
                    obstacleGrid[i][j] = 0;
                }
                else {
                   if (j > 0){
                       obstacleGrid[i][j] += obstacleGrid[i][j - 1];
                   }
                   if (i > 0) {
                       obstacleGrid[i][j] += obstacleGrid[i - 1][j];
                   }
            }
        }
        }
        return obstacleGrid[r - 1][c - 1];
    }
};
//space: O(1) since we are not using any additional space.
