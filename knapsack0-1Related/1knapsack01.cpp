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
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
       for (int i = 1; i <= n; i++){
           for (int j = 1; j <= W; j++){
               int not_including = dp[i - 1][j];
               int including = INT_MIN;
               if (wt[i - 1] <= j){
                   including = val[i - 1] + dp[i -1][j - wt[i - 1]];
               }
               dp[i][j] = max(including, not_including);
           }
       }
       return dp[n][W];
    }
}

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
// space Optimized to 1d
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<int> curr(W + 1, 0);
       for (int i = 1; i <= n; i++){
           curr[0] = 0;
           for (int j = W; j >= 1; j--){
               int including = INT_MIN;
               if (wt[i - 1] <= j){
                   including =   val[i - 1] + curr[j - wt[i - 1]];
               }
               curr[j] = max(curr[j], including);
               
           }
       }
       return curr[W];
    }
};
