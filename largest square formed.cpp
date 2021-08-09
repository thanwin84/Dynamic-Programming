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
