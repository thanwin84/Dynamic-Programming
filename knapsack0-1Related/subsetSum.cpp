//memoization 
const int D = 1001;
int  dp[D][D];
class Solution {
public:
    bool solve(int N, int arr[], int sum)
    {
        // code here
        if (N == 0 and sum == 0) {
            return true;
        }
        if (N == 0) {
            return false;
        }
        if (sum == 0) {
            return true;
        }
        if (dp[N][sum] == -1) {
            return dp[N][sum];
        }
        else {
            if (arr[N - 1] <= sum) {
                dp[N][sum] = solve(N - 1, arr, sum - arr[N - 1]) || solve(N - 1, arr, sum);
            }
            else {
                dp[N][sum] = solve(N - 1, arr, sum);
            }
            return dp[N][sum];
        }
        
    }
    int subsetSum(int N, int arr[], int sum) {
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(N, arr, sum);
    }
};

//top down approach
int  dp[D][D];
class Solution {
public:
    
    int subsetSum(int N, int arr[], int sum) {
        for (int i = 0; i <= sum; i++) {
            dp[0][i] = false;
        }
        for (int i = 0; i <= N; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[N][sum];
    }
};
