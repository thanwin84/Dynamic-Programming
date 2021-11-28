//memoization
long long int dp[1001][1001];
class Solution {
public:
    long long int count(int S[], int m, int n) {

        // code here.
        memset(dp, -1, sizeof(dp));
        return solve(S, m, n);

    }
    long long int solve(int S[], int m, int n) {
        if (dp[n][m] != -1) {
            return dp[n][m];
        }
        if (n == 0) {
            return 1;
        }
        if (m == 0) {
            return 0;
        }
        if (S[m - 1] <= n) {
            return dp[n][m] = solve(S,m,  n - S[m - 1]) + solve(S, m - 1, n);
        }
        else {
            return dp[n][m] = solve(S, m - 1, n);
        }
    }
};
// top down approach
class Solution {
  public:
    long long int count(int S[], int m, int n) {

        // code here.
        long long int dp[m + 1][n + 1];
        for (int i = 0; i <= m; i++) dp[i][0] = 1;
        for (int i = 1; i <= n; i++) dp[0][i] = 0;
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if (S[i - 1] <= j){
                    dp[i][j] = dp[i][j - S[i -1]] + dp[i -1][j];
                }
                else {
                    dp[i][j] = dp[i -1][j];
                }
            }
        }
        return dp[m][n];
    }
};
