//memoization method
int dp[1001][1001];
class Solution{
public:
    int solve(int wt[], int val[], int W, int N){
        if (W <= 0 || N == 0){
            return 0;
        }
        if (dp[N][W] != -1) return dp[N][W];
        int pick = INT_MIN;
        int notPick = solve(wt, val, W, N - 1);
        
        if (wt[N - 1] <= W){
            pick = val[N - 1] + solve(wt, val, W - wt[N - 1], N);
        }
        return dp[N][W] = max(pick, notPick);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(wt, val, W, N);
    }
};
//top down
int dp[10000][10000];
class Solution {

public:
    int unboundedKnapsack(int W, int n, int values[], int weights[])
    {
        // Your code goes here
        for (int i = 0; i <= W; i++) dp[0][i] = 0;
        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= W; j++) {
                if (weights[i - 1] <= j) {
                    dp[i][j] = max(dp[i - 1][j], values[i - 1] + dp[i][j - weights[i - 1]]);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][W];
    }
};
//space optimized solution
int dp[10000];
class Solution {

public:
    int unboundedKnapsack(int W, int n, int values[], int weights[])
    {
        // Your code goes here
        dp[0] = 0;
        for (int i = 1; i <= W; i++) dp[i] = INT_MIN;
        for (int i = 1; i <= W; i++) {
            for (int j = 0; j < n; j++) {
                if (weights[j] <= i) {
                    dp[i] = max(dp[i], dp[i - weights[j]] + 1);
                }
            }
        }
        return dp[W];
    }
};
