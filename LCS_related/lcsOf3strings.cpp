int dp[1000][1000][100];
int LCSof3 (string s1, string s2, string s3, int n1, int n2, int n3)
{
    // your code here
    for (int i = 0; i <= n1; i++){
        for (int j = 0; j <= n2; j++){
            for (int k = 0; k <= n3; k++){
                if (i == 0 || j == 0 || k == 0){
                    dp[i][j][k] = 0;
                }
                else if (s1[i - 1] == s2[j - 1] and s2[j - 1] == s3[k - 1]){
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                }
                else {
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
                }
            }
        }
    }
    return dp[n1][n2][n3];
}
