#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
#include<unordered_map>
#include<string>
using namespace std;
int dp[10000][10000];
class Solution{

	public:
	int minCoins(int coins[], int M, int V)
	{
		// Your code goes here
		for (int i = 0; i <= V; i++) {
			dp[0][i] = INT_MAX - 1;
		}
		for (int i = 1; i <= M; i++) dp[i][0] = 0;
		for (int i = 1; i <= V; i++) {
			if (i % coins[0] != 0) {
				dp[1][i] = INT_MAX - 1;
			}
			else {
				dp[1][i] = i / coins[0];
			}
		}
		for (int i = 2; i <= M; i++) {
			for (int j = 1; j <= V; j++) {
				if (coins[i - 1] <= j) {
					dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		return dp[M][V];
	}

};
int main() {
    int arr[] = { 1, 2, 3};
    Solution obj;
    cout << obj.minCoins(arr, 3, 5);
}
//space optimized-O(V)
class Solution{

	public:
	int minCoins(int coins[], int M, int V)
	{
		// Your code goes here
		dp[0] = 0;
		for (int i = 1; i <= V; i++) dp[i] = INT_MAX-1;
		for (int i = 1; i <= V; i++) {
			for (int j = 0; j < M; j++) {
				if (coins[j] <= i) {
					dp[i] = min(1 + dp[i - coins[j]], dp[i]);
				}
				else continue;
			}
		}
		if (dp[V] == INT_MAX - 1){
		    return -1;
		}
		else {
		    return dp[V];
		}
	}

};
