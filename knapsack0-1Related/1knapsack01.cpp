//recursive
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       if (W == 0 || n == 0){
           return 0;
       }
       int including = INT_MIN, not_including = INT_MIN;
       if (wt[n -1] <= W){
           including = val[n -1] + solve(W - wt[n -1], wt, val, n -1);
       }
       not_including = solve(W, wt, val, n -1);
       return max(including, not_including);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       return solve(W, wt, val, n);
    }
};
//memoization
//time: O(n*W) and space: O(n*W)
int dp[1001][1001];
class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int W, int wt[], int val[], int n) {
        if (n == 0) {
            if (wt[0] <= W) return val[0];
            return 0;
        }
        int pick = 0, notPick = 0;
        if (dp[n][W] != -1) {
            return dp[n][W];
        }
        if (wt[n] <= W) {
            pick = val[n] + solve(W - wt[n], wt, val, n - 1);
        }
        notPick = solve(W, wt, val, n - 1);
        return dp[n][W] = max(pick, notPick);
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        memset(dp, -1, sizeof(dp));

        return solve(W, wt, val, n - 1);
       
    }
};
   
//top down approach
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        for (int i = 0; i <= W; i++) {
            if (wt[0] <= i) dp[0][i] = val[0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= W; j++) {
                int pick = 0, notPick = 0;
                if (wt[i] <= j) {
                    pick = val[i] + dp[i - 1][j - wt[i]];
                }
                notPick = dp[i - 1][j];
                dp[i][j] = max(pick, notPick);
                
            }
        }
        return dp[n - 1][W];
    }
};
// space optimized solution
// space: O(W)
lass Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<int> curr(W + 1, 0), prev(W + 1, 0);
       for (int i = 1; i <= n; i++){
           for (int j = 1; j <= W; j++){
               int not_including = prev[j];
               int including = INT_MIN;
               if (wt[i - 1] <= j){
                   including = val[i - 1] + prev[j - wt[i - 1]];
               }
               curr[j] = max(including, not_including);
           }
           prev = curr;
       }
       return prev[W];
    }
};
// space: O(W)
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<int> curr(W + 1, 0);
       vector<int> prev(W + 1, 0);
        for (int i = 0; i <= W; i++) {
            if (wt[0] <= i) prev[i] = val[0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= W; j++) {
                int pick = 0, notPick = 0;
                if (wt[i] <= j) {
                    pick = val[i] + prev[j - wt[i]];
                }
                notPick = prev[j];
                curr[j] = max(pick, notPick);
            }
            prev = curr;
        }
        return prev[W];
    }
};
