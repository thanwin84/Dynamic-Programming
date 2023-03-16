// single matrix: [10, 20, 30, 40]
// matrix: a = 10 * 20, B = 20 * 30, C = 30 * 40
//recursive
class Solution {
public:
    int Solve(int arr[], int i, int j) {
        // single matrix
        if (i >= j) {
            return 0;
        }
        int _min = INT_MAX;
        for (int k = i; k < j; k++) {
            int left = Solve(arr, i, k);
            int right = Solve(arr, k + 1, j);
            int cost = arr[i - 1] * arr[k] * arr[j];
            int temp_ans = left + right + cost;
            _min = min(temp_ans, _min);
        }
        return _min;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int i = 1;
        int j = N - 1;
        int result = Solve(arr, i, j);
        return result;
    }
};
#bottom up
int dp[1002][1002];
class Solution {
public:
    int solve(int arr[], int i, int j) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (i >= j) {
            return 0;
        }
        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            int left = solve(arr, i, k);
            int right = solve(arr, k + 1, j);
            int cost = arr[i - 1] * arr[k] * arr[j];
            int temp = left + right + cost;
            ans = min(ans, temp);
        }
        return dp[i][j] = ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(arr, 1, N - 1);
    }
};
