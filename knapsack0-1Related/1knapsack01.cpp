//recursive
class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSackRe(int W, int wt[], int val[], int n)
    {
        // Your code here
        if (W == 0 or n == 0) {
            return 0;
        }
        if (wt[n - 1] >= W) {
            return max(val[n - 1] + knapSackRe(W - wt[n - 1], wt, val, n - 1), knapSackRe(W, wt, val, n - 1));
        }
        else {
            return knapSackRe(W, wt, val, n - 1);
        }
    }
    
};
//memoization
//time: O(n*W) and space: O(n*W)
const int D = 1001;
int  dp[D][D];
class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSackRe(int W, int wt[], int val[], int n)
    {
        // Your code here
        if (n == 0 || W == 0) {
            return 0;
        }
        if (dp[n][W] != -1) {
            return dp[n][W];
        }
        else {
            if (wt[n - 1] <= W) {
                dp[n][W] = max(val[n - 1] + knapSackRe(W - wt[n - 1], wt, val, n - 1), knapSackRe(W, wt, val, n - 1));
            }
            else {
                dp[n][W] = knapSackRe(W, wt, val, n - 1);
            }
            return dp[n][W];
        }
        
    }
    int knapSack(int W, int wt[], int val[], int n) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= W; j++) {
                dp[i][j] = -1;
            }
        }
        return knapSackRe(W, wt, val, n);
    }
    
};
   
//top down approach
const int D = 1001;
int  dp[D][D];
class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= W; j++) {
                if (i == 0 || j == 0) dp[i][j] = 0;
                else if (wt[i - 1] <= j) {
                    int included = val[i - 1] + dp[i - 1][j - wt[i - 1]];
                    int not_included = dp[i - 1][j];
                    dp[i][j] = max(included, not_included);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][W];
    }
};