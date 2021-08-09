// Memoization
//time: O(n*m) and space: O(n*m)
int dp[52][52];
class Solution {

public:
    int result;
    int solve(int row, int col, vector<vector<int>>& mat, int n, int m) {
        if (row <= 0 or col <= 0) {
            return 0;
        }
        if (dp[row][col] != -1) {
            return dp[row][col];
        }
        int diogonal = solve(row -1 , col -1, mat, n, m);
        int left = solve(row, col -1, mat, n, m);
        int up = solve(row -1, col, mat, n, m);
        dp[row][col] = 0;
        if (mat[row -1][col -1] == 1) {
            dp[row][col] = 1 + min(diogonal, min(left, up));
            result = max(result, dp[row][col]);
        }
        return dp[row][col];
    }
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        memset(dp, -1, sizeof(dp));
        solve(n, m,  mat, n, m);
        return result;
    }
};
//top down
int dp[52][52];
class Solution {
public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        for (int i = 0; i <= m; i++) dp[0][i] = 0;
        int row = n;
        int col = m;
        int result = 0;
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                if (mat[i -1][j -1] == 1){
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
                    result = max(result, dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return result;
    }
};
