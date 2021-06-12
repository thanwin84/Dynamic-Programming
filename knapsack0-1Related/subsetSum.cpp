//memoization 
const int D = 1001;
int  dp[D][D];
class Solution {
public:
    int solve(int N, int arr[], int sum)
    {
        // code here
        if (N == 0 and sum == 0) {
            return true;
        }
        else if (N == 0) {
            return false;
        }
        else if (sum == 0) {
            return true;
        }
        if (dp[N][sum] != -1) {
           
            dp[N][sum] = solve(N - 1, arr, sum - arr[N - 1]) || solve(N-1, arr, sum);
        }
        else {
            dp[N][sum] = solve(N - 1, arr, sum);
        }
        return dp[N][sum];
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
