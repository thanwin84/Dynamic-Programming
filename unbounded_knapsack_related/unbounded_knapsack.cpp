//memoization method
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
class Solution {

public:
    int solve(int W, int n, int values[], int weights[]) {
        if (n == 0) {
            return 0;
        }
        if (W <= 0) {
            return 0;
        }
        if (dp[n][W] != -1) {
            return dp[n][W];
        }
        else {
            if (weights[n - 1] <= W) {
                dp[n][W] = max(values[n - 1] + solve(W - weights[n - 1], n, values, weights), solve(W, n - 1, values, weights));
            }
            else {
                dp[n][W] = solve(W, n - 1, values, weights);
            }
            return dp[n][W];
        }
    }
    int unboundedKnapsack(int W, int n, int values[], int weights[])
    {
        // Your code goes here
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= W; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(W, n, values, weights);
    }
};
int main() {
    int W = 100;
    int val[] = { 10, 30, 20 };
    int wt[] = { 5, 10, 15 };
    Solution obj;
    cout << obj.unboundedKnapsack(W, 3, val, wt) << endl;
    return 0;
}
