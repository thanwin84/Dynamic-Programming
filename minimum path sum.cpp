//top down
class Solution {
    int dp[201][201];
public:
    int solve(vector<vector<int>> & grid, int r, int c){
        if (r < 0 || c < 0){
            return INT_MAX;
        }
        if (c == 0 && r == 0){
            return grid[r][c]; 
        }
        if (dp[r][c] != -1){
            return dp[r][c];
        }
        int left = solve(grid, r -1, c);
        int right = solve(grid, r, c - 1);
        return dp[r][c] = grid[r][c] + min(left, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        memset(dp, -1, sizeof(dp));
        int result = solve(grid, row -1, col -1);
        
        return result;
    }
};
//time: O(n * m) and space: O(n + m)


//iterative approach
class Solution {
    int dp[201][201];
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        dp[0][0] = grid[0][0];
        for (int i = 1; i < r; i++) dp[i][0] = dp[i -1][0] + grid[i][0];
        for (int i = 1; i < c; i++) dp[0][i] = dp[0][i -1] + grid[0][i];
        for (int i = 1; i < r; i++){
            for (int j = 1; j < c; j++){
                dp[i][j] = grid[i][j] + min(dp[i -1][j], dp[i][j - 1]);
            }
        }
        return dp[r -1][c -1];
    }
};
//time: O(n * m) and space: O(n + m)
//if we observe closely, we only need grid[i][j] value for once. we dont need to use it later.we can store value at grid[i][j] for future calculation
//Space optimized Solution
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        for (int i = 1; i < r; i++) grid[i][0] = grid[i -1][0] + grid[i][0];
        for (int i = 1; i < c; i++) grid[0][i] = grid[0][i -1] + grid[0][i];
        for (int i = 1; i < r; i++){
            for (int j = 1; j < c; j++){
                grid[i][j] = grid[i][j] + min(grid[i -1][j], grid[i][j - 1]);
            }
        }
        return grid[r -1][c -1];
    }
};
//space: O(1)
