//top down approach
//time: O(n * m) and space: O(n * m)
class Solution {
    int dp[101][101];
public:
    int solve(int r, int c, int row, int col){
        if (r == 0 && c == 0){
            return 1;
        }
        if (r < 0 || c < 0){
            return 0;
        }
        if (dp[r][c] != -1){
            return dp[r][c];
        }
        int left = solve(r, c - 1, row, col);
        int right = solve(r -1, c, row, col);
        return dp[r][c] = left + right;
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(m -1, n -1, m, n);
    }
};
//iterative approach
class Solution {
    int dp[101][101];
public:
    int uniquePaths(int m, int n) {
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (i == 0 || j == 0){
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i -1][j] + dp[i][j -1];
                }
            }
        }
        return dp[m - 1][n -1];
    }
};
