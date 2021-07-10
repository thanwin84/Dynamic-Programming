//memoization
int dp[1003][1003];
class Solution {
public:
    bool isSubsetSumRe(int N, int arr[], int sum) {
        if (dp[N][sum] != -1) {
            return dp[N][sum];
        }
        // code here 
        if (sum == 0) {
            return true;
        }
        if (N == 0) {
            return false;
        }
        if (arr[N - 1] <= sum) {
            bool included = isSubsetSumRe(N - 1, arr, sum - arr[N - 1]);
            bool not_included = isSubsetSumRe(N - 1, arr, sum);
            return dp[N][sum] = included || not_included;
        }
        else {
            return dp[N][sum] = isSubsetSumRe(N - 1, arr, sum);
        }
    }
    bool isSubsetSum(int N, int arr[], int sum) {
        memset(dp, -1, sizeof(dp));
        return isSubsetSumRe(N, arr, sum);
    }
};
//top down approach 
int dp[103][100000];
class Solution {
public:
    bool isSubsetSum(int N, int arr[], int sum) {
        // code here 
        for (int i = 0; i <= N; i++) dp[i][0] = true;
        for (int i = 1; i <= sum; i++) dp[0][i] = false;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[N][sum];
    }
};
