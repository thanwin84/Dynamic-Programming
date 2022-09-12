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
        if (dp[row][aCol][bCol] != -1){
            return dp[row][aCol][bCol];
        }
        vector<int> y_coordinates = { -1, 0, 1 };
        int ans = 0;
//       explore all tha paths
        for (int nextAcol = 0; nextAcol < 3; nextAcol++) {
            for (int nextBcol = 0; nextBcol < 3; nextBcol++) {
                int value = 0;
                if (aCol == bCol) value = grid[row][aCol];
                else value = grid[row][aCol] + grid[row][bCol];
                int temp = value + solve(grid, row + 1, aCol + y_coordinates[nextAcol], bCol + y_coordinates[nextBcol]);
                ans = max(ans, temp);
            }
        }
        return dp[row][aCol][bCol] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1, sizeof(dp));
        return solve(grid, 0, 0, grid[0].size() - 1);
    }
};
