//memoization 
int dp[1000][10000];
class Solution{

	public:
	int solve(int arr[], int n, int sum){
	    if (sum == 0){
	        return 1;
	    }
	    if (n == 0){
	        return 0;
	    }
	    if (dp[n][sum] != -1){
	        return dp[n][sum];
	    }
	    if (arr[n - 1] <= sum){
	        int included = solve(arr, n - 1, sum - arr[n -1]) % 1000000007;
	        int excluded = solve(arr, n - 1, sum) % 1000000007;
	        return dp[n][sum] = (included + excluded)  %1000000007; 
	    }
	    else {
	        return dp[n][sum] = solve(arr, n - 1, sum);
	    }
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        memset(dp, -1, sizeof(dp));
        return solve(arr, n, sum);
	}
	  
};


//top down
#include <bits/stdc++.h> 
using namespace std;
int findWays(vector<int> &num, int tar)
{
    // Write your code here
    int n = num.size();
    vector<vector<int>> dp(n + 1, vector<int>(tar + 1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int ind = 1; ind <= n; ind++){
        for (int sum = 0; sum <= tar; sum++){
            int notTaken = dp[ind - 1][sum];
            int taken = 0;
            if (num[ind - 1] <= sum) taken = dp[ind - 1][sum - num[ind - 1]];
            
            dp[ind][sum] = taken + notTaken;
        }
    }
    return dp[n][tar];
    
}
