// time: O(N * M * M) * 9
// space: O(N * M * M) + O(N) [stack space]
int dp[71][71][71];
class Solution {
public:
    int solve(vector<vector<int>>& grid, int row, int aCol, int bCol) {
        int rows = grid.size();
        int cols = grid[0].size();
        // check boundary cases
        if (row >= rows || aCol < 0 || aCol >= cols || bCol < 0 || bCol >= cols) {
            return 0;
        }
        // at the desination row
        if (row == rows - 1) {
            if (aCol == bCol) {
                return grid[row][aCol];
            }
            else {
                return grid[row][aCol] + grid[row][bCol];
            }
        }
        if (dp[row][aCol][bCol] != -1) {
            return dp[row][aCol][bCol];
        }
        vector<int> y_coordinates = { -1, 0, 1 };
        int ans = 0;
        // explore all tha paths
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int value = 0;
                if (aCol == bCol) value = grid[row][aCol];
                else value = grid[row][aCol] + grid[row][bCol];
                int nextAcol = aCol + y_coordinates[i];
                int nextBcol = bCol + y_coordinates[j];
                int temp = value + solve(grid, row + 1, nextAcol, nextBcol);
                ans = max(ans, temp);
            }
        }
        return dp[row][aCol][bCol] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, grid[0].size() - 1);
    }
};
// iterative approach
int dp[71][71][71];
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int ans = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        // base case
        for (int aCol = 0; aCol < cols; aCol++) {
            for (int bCol = 0; bCol < cols; bCol++) {
                if (aCol == bCol) dp[rows - 1][aCol][bCol] = grid[0][aCol];
                else dp[rows - 1][aCol][bCol] = grid[rows - 1][aCol] + grid[rows - 1][bCol];
            }
        }
 
        vector<int> y_coordinates = { -1, 0, 1 };
        for (int row = rows - 2; row >= 0; row--) {
            for (int aCol = 0; aCol < cols; aCol++) {
                for (int bCol = 0; bCol < cols; bCol++) {


                    // all posibble 9 paths
                    int ans = 0;
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            int value = 0;
                            if (aCol == bCol) value = grid[row][aCol];
                            else value = grid[row][aCol] + grid[row][bCol];
                            int nextAcol = aCol + y_coordinates[i];
                            int nextBcol = bCol + y_coordinates[j];
                            int temp = 0;
                            if (row >= rows || nextAcol < 0 || nextAcol >= cols || nextBcol < 0 || nextBcol >= cols) {
                                temp = value + 0;
                            }
                            else temp = value + dp[row + 1][nextAcol][nextBcol];
                            ans = max(ans, temp);
                        }
                    }
                    dp[row][aCol][bCol] = ans;
                }
            }
        }
        return dp[0][0][cols - 1];
    }
};
