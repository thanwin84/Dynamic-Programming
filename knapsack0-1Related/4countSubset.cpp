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
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
#include<unordered_map>
#include<string>
#define mod 1000000007
using namespace std;
int dp[201][10002];
class Solution {
public:
    int count_subset(vector<int>& nums, int sum) {
      
        
        for (int i = 0; i <= sum; i++) dp[0][i] = 0;
	// we can always make empty set 
        for (int i = 0; i <= nums.size(); i++) dp[i][0] = 1;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= sum ; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[nums.size()][sum];

    }
};
int main() {
	Solution ob;
    vector<int> nums = { 1, 2, 3, 3};
    cout << ob.count_subset(nums, 6);
   
	return 0;
}
