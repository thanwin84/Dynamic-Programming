//memoization method
int dp[1001][1001];
class Solution{
public:
    int solve(int wt[], int val[], int W, int N){
        // if bag is empty or no items to choose
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
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
        for (int ind = 1; ind <= N; ind++){
            for (int capacity= 1; capacity <= W; capacity++){
                int notPick = dp[ind - 1][capacity];
                int pick = 0;
                if (wt[ind - 1] <= capacity){
                    pick = val[ind - 1] + dp[ind][capacity - wt[ind - 1]];
                }
                dp[ind][capacity] = max(pick, notPick);
                
            }
        }
        return dp[N][W];
    }
};
//space optimized solution
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<int> prev(W + 1, 0), curr(W + 1, 0);
        for (int ind = 1; ind <= N; ind++){
            for (int capacity= 1; capacity <= W; capacity++){
                int notPick = prev[capacity];
                int pick = 0;
                if (wt[ind - 1] <= capacity){
                    pick = val[ind - 1] + curr[capacity - wt[ind - 1]];
                }
                curr[capacity] = max(pick, notPick);
            }
            prev = curr;
        }
        return prev[W];
    }
};
