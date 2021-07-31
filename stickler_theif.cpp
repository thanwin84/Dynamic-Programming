nt dp[10002];
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSumHelper(int arr[], int n)
    {
        // Your code here
        if (n <= 0){
            return 0;
        }
        if (n == 1){
            return arr[n-1];
        }
        if (dp[n] != -1){
            return dp[n];
        }
        int including = arr[n - 1] + FindMaxSumHelper(arr, n -2);
        int not_including = FindMaxSumHelper(arr, n -1);
        return dp[n] =  max(including, not_including);
    }
    int FindMaxSum(int arr[], int n){
        memset(dp, -1, sizeof(dp));
        return FindMaxSumHelper(arr, n);
    }
};
// top-down approach
int dp[10002];
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n){
        dp[0] = 0;
        dp[1] = arr[0];
        dp[2] = max(arr[0], arr[1]);
        for (int i = 3; i <= n; i++){
            dp[i] = max(arr[i-1] + dp[i -2], dp[i - 1]);
        }
        return dp[n];
    }
    
};
