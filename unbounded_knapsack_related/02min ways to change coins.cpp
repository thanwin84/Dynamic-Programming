//memoization 
int dp[13][10001];
class Solution {
public:
    int solve(vector<int> &coins, int amount, int N){
        if (amount == 0) return 0;
        if (N == 0) return 10001;
        if (dp[N][amount] != -1) return dp[N][amount];
        int included = solve(coins, amount, N - 1);
        int notIncluded = 10001;
        if (coins[N - 1] <= amount){
            notIncluded = 1 + solve(coins, amount - coins[N - 1], N);
        }
        return dp[N][amount] = min(included, notIncluded);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int result = solve(coins, amount, coins.size());
        if (result == 10001){
            return -1;
        }
        return result;
    }
};
//time O(n*m) and space: O(n*m)
int dp[13][10001];
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, amount + 1));
        for (int i = 1; i <= n; i++) dp[i][0] = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= amount; j++){
                int notIncluded = dp[i - 1][j];
                int included = amount + 1;
                if (coins[i - 1] <= j) included = 1 + dp[i][j - coins[i - 1]];
                dp[i][j] = min(included, notIncluded);
            }
        }
        int result = dp[n][amount];
        if (result == amount + 1) return -1;
        return result;
    }
};
//coin change for leetcode
//space optimized
int dp[13][10001];
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, amount + 1);
        for (int i = 1; i <= n; i++){
            dp[0] = 0;
            for (int j = 1; j <= amount; j++){
                int notIncluded = dp[j];
                int included = amount + 1;
                if (coins[i - 1] <= j) included = 1 + dp[j - coins[i - 1]];
                dp[j] = min(included, notIncluded);
            }
        }
        int result = dp[amount];
        if (result == amount + 1) return -1;
        return result;
    }
};
