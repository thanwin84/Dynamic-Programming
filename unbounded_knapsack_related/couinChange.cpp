//time O(n*m) and space: O(n*m)
long long int dp[1000][1000];
class Solution
{
  public:
    long long int count( int coins[], int m, int n )
    {
       
        //code here.
        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (coins[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
};
//coin change for leetcode
//space optimized
int dp[10000];
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0){
            return 0;
        }
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) dp[i] = INT_MAX -1;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX -1) {
            return -1;
        }
        else {
            return dp[amount];
        }
    }
};
